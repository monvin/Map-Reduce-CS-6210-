#pragma once

#include "mapreduce_spec.h"
#include "file_shard.h"
#include <thread>

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>

#include <masterworker.grpc.pb.h>

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using masterworker::WorkerReq;
using masterworker::WorkDetails;
using masterworker::WorkConfirmation;
using masterworker::FileInfo;

/* RPC implementation adapted from https://github.com/grpc/grpc/tree/master/examples/cpp/helloworld */

/* Time to wait for a slow worker, in order of 100 msec */
#define WAIT_PERIOD                (50)

/* CS6210_TASK: Handle all the bookkeeping that Master is supposed to do.
	This is probably the biggest task for this project, will test your understanding of map reduce */
class Master {

	public:
		/* DON'T change the function signature of this constructor */
		Master(const MapReduceSpec&, const std::vector<FileShard>&);

		/* DON'T change this function's signature */
		bool run();

	private:
		/* NOW you can add below, data members and member functions as per the need of your implementation*/
    MapReduceSpec calculated_spec;
    std::vector<FileShard> calculated_shrad;
};


/* CS6210_TASK: This is all the information your master will get from the framework.
	You can populate your other class data members here if you want */
Master::Master(const MapReduceSpec& mr_spec, const std::vector<FileShard>& file_shards) {
  calculated_spec = mr_spec;
  calculated_shrad = file_shards;
  int check;
  
    system("rm -rf intermediate");
    if (mkdir("intermediate", 0777) == -1)
    {
      std::cerr << "Error :  " << strerror(errno) << std::endl;
    }
    std::string delete_dir = mr_spec.output_dir.c_str();
    std::string delete_cmd = "rm -rf " + delete_dir;
    system(delete_cmd.c_str());
    if (mkdir(mr_spec.output_dir.c_str(), 0777) == -1)
	{
      std::cerr << "Error :  " << strerror(errno) << std::endl;
	}
    if (calculated_spec.n_output_files > calculated_shrad.size())
    {
      database_init(calculated_spec.n_workers, calculated_spec.n_output_files);
    }
    else
    {
      database_init(calculated_spec.n_workers, calculated_shrad.size());
    }
}

class WorkerClient {
 public:
  explicit WorkerClient(std::shared_ptr<Channel> channel, unsigned int id)
      : stub_(WorkerReq::NewStub(channel)), worker_id(id) {}

  // Assembles the client's payload and sends it to the server.
  void CallMapper(struct FileShard& shrad, MapReduceSpec& spec, int job_id) {
    // Data we are sending to the server.
    WorkDetails request;
    request.set_initial_file_start(shrad.start);
    request.set_job_id(job_id);
    request.set_is_mapper(true);
    request.set_file_count(spec.n_output_files);
    for (int i = 0; i < shrad.input_files.size(); i++)
    {
      FileInfo *info_ptr = request.add_filedetails();
      info_ptr->set_input_file(shrad.input_files[i]);
      info_ptr->set_file_offset(shrad.files_offset[i]);
    }
    request.set_user_id(spec.user_id);
    // Call object to store rpc data
    AsyncClientCall* call = new AsyncClientCall;

    // stub_->PrepareAsyncperformtask() creates an RPC object, returning
    // an instance to store in "call" but does not actually start the RPC
    // Because we are using the asynchronous API, we need to hold on to
    // the "call" instance in order to get updates on the ongoing RPC.
    call->response_reader =
        stub_->PrepareAsyncperformtask(&call->context, request, &cq_);

    // StartCall initiates the RPC call
    call->response_reader->StartCall();

    // Request that, upon completion of the RPC, "reply" be updated with the
    // server's response; "status" with the indication of whether the operation
    // was successful. Tag the request with the memory address of the call
    // object.
    call->response_reader->Finish(&call->reply, &call->status, (void*)call);
  }

  // Assembles the client's payload and sends it to the server.
  void CallReducer(std::vector<unsigned int> mapper_jobs, std::string user_id, int reducer_id) {
    // Data we are sending to the server.
    WorkDetails request;
    request.set_job_id(reducer_id);
    request.set_is_mapper(false);
    for (int i = 0; i < mapper_jobs.size(); i++)
    {
      request.add_completed_jobs(mapper_jobs[i]);
    }
    request.set_user_id(user_id);
    // Call object to store rpc data
    AsyncClientCall* call = new AsyncClientCall;

    // stub_->PrepareAsyncperformtask() creates an RPC object, returning
    // an instance to store in "call" but does not actually start the RPC
    // Because we are using the asynchronous API, we need to hold on to
    // the "call" instance in order to get updates on the ongoing RPC.
    call->response_reader =
        stub_->PrepareAsyncperformtask(&call->context, request, &cq_);

    // StartCall initiates the RPC call
    call->response_reader->StartCall();

    // Request that, upon completion of the RPC, "reply" be updated with the
    // server's response; "status" with the indication of whether the operation
    // was successful. Tag the request with the memory address of the call
    // object.
    call->response_reader->Finish(&call->reply, &call->status, (void*)call);
  }

  // Loop while listening for completed responses.
  void AsyncCompleteRpc() {
    void* got_tag;
    bool ok = false;
    bool rpc_failure = false;

    // Block until the next result is available in the completion queue "cq".
    while ((cq_.Next(&got_tag, &ok)) && (rpc_failure == false)) {
      // The tag in this example is the memory location of the call object
      AsyncClientCall* call = static_cast<AsyncClientCall*>(got_tag);

      // Verify that the request was completed successfully. Note that "ok"
      // corresponds solely to the request for updates introduced by Finish().
      GPR_ASSERT(ok);

      if (call->status.ok())
      {
        finish_job(worker_id, call->reply.job_id());
      }
      else
      {
        std::cout << "RPC failed" << std::endl;
        rpc_failure = true;
      }
      // Once we're complete, deallocate the call object.
      delete call;
    }
  }

 private:
  // struct for keeping state and data information
  struct AsyncClientCall {
    // Container for the data we expect from the server.
    WorkConfirmation reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // Storage for the status of the RPC upon completion.
    Status status;

    std::unique_ptr<ClientAsyncResponseReader<WorkConfirmation>> response_reader;
  };

  // Out of the passed in Channel comes the stub, stored here, our view of the
  // server's exposed services.
  std::unique_ptr<WorkerReq::Stub> stub_;

  // The producer-consumer queue we use to communicate asynchronously with the
  // gRPC runtime.
  CompletionQueue cq_;
  unsigned int worker_id;
};

/* CS6210_TASK: Here you go. once this function is called you will complete whole map reduce task and return true if succeeded */
bool Master::run() {
  std::vector<WorkerClient *> ClientList;
  std::vector<std::thread> ThreadList;
  int next_worker;
  bool pending_worker;
  unsigned int wait_count;
  unsigned int new_job_id;
  bool tracker;

  for (unsigned int i = 0; i < calculated_spec.n_workers; i++)
  {
    WorkerClient *clientobj = new WorkerClient(grpc::CreateChannel(
      calculated_spec.worker_ipaddr_ports[i], grpc::InsecureChannelCredentials()), i);
    ClientList.push_back(clientobj);
  }
  // Spawn reader thread that loops indefinitely
  for (unsigned int i = 0; i < calculated_spec.n_workers; i++)
  {
    ThreadList.push_back(std::thread(&WorkerClient::AsyncCompleteRpc, &(*ClientList[i])));
  }
  set_max_job_count( calculated_shrad.size());
  for (int i = 0; i < calculated_shrad.size(); i++) {
    next_worker = get_free_worker_id();
    while (next_worker == -1)
    {
      next_worker = get_free_worker_id();
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    start_job(next_worker, i);
    (*(ClientList[next_worker])).CallMapper(calculated_shrad[i], calculated_spec, i);
  }
  pending_worker = true;
  while (pending_worker == true)
  {
    wait_count = 0;
    tracker = is_task_pending();
    while ((tracker == true) && (wait_count < WAIT_PERIOD))
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      wait_count++;
      tracker = is_task_pending();
    }
    if (tracker == true)
    {
      for (unsigned int i = 0; i < calculated_shrad.size(); i++)
      {
        if (is_job_completed(i) == false)
        {
          next_worker = get_free_worker_id();
          while (next_worker == -1)
          {
            next_worker = get_free_worker_id();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
          }
          new_job_id = get_job_id_from_index(i);
          new_job_id = new_job_id + calculated_shrad.size();
          start_job(next_worker, new_job_id);
          (*(ClientList[next_worker])).CallMapper(calculated_shrad[i], calculated_spec, new_job_id);
        }
      }
    }
    else
    {
      pending_worker = false;
    }
  }
  std::vector<unsigned int> mapper_job_list(calculated_shrad.size());
  for (unsigned int i = 0; i < calculated_shrad.size(); i++)
  {
    mapper_job_list[i] = get_job_id_from_index(i);
  }
  database_reset();
  set_max_job_count(calculated_spec.n_output_files);
  for (int i = 0; i < calculated_spec.n_output_files; i++) {
    next_worker = get_free_worker_id();
    while (next_worker == -1)
    {
       next_worker = get_free_worker_id();
       std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    start_job(next_worker, i);
    (*(ClientList[next_worker])).CallReducer(mapper_job_list, calculated_spec.user_id, i);
  }
  pending_worker = true;
  while (pending_worker == true)
  {
    wait_count = 0;
    tracker = is_task_pending();
    while ((tracker == true) && (wait_count < WAIT_PERIOD))
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      wait_count++;
      tracker = is_task_pending();
    }
    if (tracker == true)
    {
      for (unsigned int i = 0; i < calculated_spec.n_output_files; i++)
      {
        if (is_job_completed(i) == false)
        {
          next_worker = get_free_worker_id();
          while (next_worker == -1)
          {
            next_worker = get_free_worker_id();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
          }
          new_job_id = get_job_id_from_index(i);
          new_job_id += calculated_spec.n_output_files;
          start_job(next_worker, new_job_id);
           (*(ClientList[next_worker])).CallReducer(mapper_job_list, calculated_spec.user_id, new_job_id);
        }
      }
    }
    else
    {
      pending_worker = false;
    }
  }
  std::cout << "Press control-c to quit" << std::endl << std::endl;
  for (unsigned int i = 0; i < calculated_spec.n_workers; i++)
  {
    ThreadList[i].join();
  }
}