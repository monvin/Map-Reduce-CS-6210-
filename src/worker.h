#pragma once

#include <mr_task_factory.h>
#include "mr_tasks.h"

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>

#include <masterworker.grpc.pb.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

using masterworker::WorkerReq;
using masterworker::WorkDetails;
using masterworker::WorkConfirmation;

extern std::shared_ptr<BaseMapper> get_mapper_from_task_factory(const std::string& user_id);
extern std::shared_ptr<BaseReducer> get_reducer_from_task_factory(const std::string& user_id);

/* RPC implementation adapted from https://github.com/grpc/grpc/tree/master/examples/cpp/helloworld */

/* CS6210_TASK: Handle all the task a Worker is supposed to do.
	This is a big task for this project, will test your understanding of map reduce */
class Worker {

	public:
		/* DON'T change the function signature of this constructor */
		Worker(std::string ip_addr_port);

		/* DON'T change this function's signature */
		bool run();
		~Worker() {
          server_->Shutdown();
          // Always shutdown the completion queue after the server.
          cq_->Shutdown();
        }

	private:
     
	    // Class encompasing the state and logic needed to serve a request.
        class CallData {
          public:
            // Take in the "service" instance (in this case representing an asynchronous
            // server) and the completion queue "cq" used for asynchronous communication
            // with the gRPC runtime.
            CallData(WorkerReq::AsyncService* service, ServerCompletionQueue* cq)
            : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {
              // Invoke the serving logic right away.
              Proceed();
            }

            void Proceed() {
              if (status_ == CREATE) {
              // Make this instance progress to the PROCESS state.
              status_ = PROCESS;

              // As part of the initial CREATE state, we *request* that the system
              // start processing SayHello requests. In this request, "this" acts are
              // the tag uniquely identifying the request (so that different CallData
              // instances can serve different requests concurrently), in this case
              // the memory address of this CallData instance.
              service_->Requestperformtask(&ctx_, &request_, &responder_, cq_, cq_,
                                  this);
              } else if (status_ == PROCESS) {
                // Spawn a new CallData instance to serve new clients while we process
                // the one for this CallData. The instance will deallocate itself as
                // part of its FINISH state.
                new CallData(service_, cq_);
                 // The actual processing.
                if (request_.is_mapper() == true)
                {
                  std::string intermediate_file_name;
                  std::shared_ptr<BaseMapper> mapper_ptr;
                  mapper_ptr = get_mapper_from_task_factory(request_.user_id());
                  mapper_ptr->impl_->intermediate_file_vec.resize(request_.file_count(), NULL);
                  mapper_ptr->impl_->intermediate_file_count = request_.file_count();
                  mapper_ptr->impl_->cur_user_id = request_.user_id();
				  
                  for (long i = 0; i < request_.file_count(); i++)
                  {
                    intermediate_file_name = "intermediate//"+request_.user_id() + "_" + std::to_string((int)request_.job_id()) + "_" + std::to_string(i) + ".txt";
                    mapper_ptr->impl_->intermediate_file_vec[i] = fopen(intermediate_file_name.c_str(), "w");
                  }
                  bool first_file = true;
                  for (auto details:request_.filedetails())
                  {
                    if (first_file == true)
                    {
                      read_lines_from_file(details.input_file(), request_.initial_file_start(), details.file_offset(), mapper_ptr);
                      first_file = false;
                    }
                    else
                    {
                      read_lines_from_file(details.input_file(), 0, details.file_offset(), mapper_ptr);
                    }
                  }
                  for (long i = 0; i < request_.file_count(); i++)
                  {
                    fclose(mapper_ptr->impl_->intermediate_file_vec[i]);
                  }
                  reply_.set_is_mapper(true);
                }
                else
                {
                  reply_.set_is_mapper(false);
                  std::string intermediate_file_name;
                  std::string output_file_name;
                  std::shared_ptr<BaseReducer> reducer_ptr;
                  reducer_ptr = get_reducer_from_task_factory(request_.user_id());
                  int i = 0;
                  output_file_name = "output//output_" + request_.user_id() + "_" + std::to_string((int)request_.job_id()) + ".txt"; 
                  reducer_ptr->impl_->f_ptr = fopen(output_file_name.c_str(), "w");
                  for (auto mapper_job:request_.completed_jobs())
                  {
                    intermediate_file_name = "intermediate//" + request_.user_id() + "_" + std::to_string((int)mapper_job) + "_" + std::to_string((int)request_.job_id()) + ".txt";
                    read_lines_from_intermediate_file(intermediate_file_name, reducer_ptr);
                  }
                  std::map<std::string, std::vector<std::string> >::iterator it;
                  for (it = reducer_ptr->impl_->user_reducer_output.begin(); it != reducer_ptr->impl_->user_reducer_output.end(); it++)
                  reducer_ptr->reduce(it->first, reducer_ptr->impl_->user_reducer_output[it->first]);
                  fclose(reducer_ptr->impl_->f_ptr);
                }
                reply_.set_job_id(request_.job_id());
                // And we are done! Let the gRPC runtime know we've finished, using the
                // memory address of this instance as the uniquely identifying tag for
                // the event.
                status_ = FINISH;
                responder_.Finish(reply_, Status::OK, this);
              } else {
                GPR_ASSERT(status_ == FINISH);
                // Once in the FINISH state, deallocate ourselves (CallData).
                delete this;
              }
            }
          private:
          void read_lines_from_file(std::string file_name, double file_start, double file_offset, std::shared_ptr<BaseMapper> mapper_ptr)
          { 
            FILE * file_ptr;
            size_t line_len = 0;
            ssize_t read_ret;
            char * read_line = NULL;
            
            file_ptr = fopen(file_name.c_str(), "r");
            if (file_ptr == NULL)
            {
              std::cout << "ERROR: input file not found" << std::endl;
            }
            fseek(file_ptr, file_start, SEEK_SET);
            bool flag = true;
            while (((read_ret = getline(&read_line, &line_len, file_ptr)) != -1) && (ftell(file_ptr) < (file_start + file_offset)))
            {
              if (flag == true)
              {
                flag = false;
              }
              if(read_line[read_ret-1] == '\n')
              read_line[read_ret-1] = '\0';
              mapper_ptr->map(read_line);
            }
            if (read_ret != -1)
            {
		      //  ftell became out of bound after reading a valid line which is yet to be processed 
              if(read_line[read_ret-1] == '\n')
			  {
                read_line[read_ret-1] = '\0';
			  }
              mapper_ptr->map(read_line);
            }
            fclose(file_ptr);
          }

          void read_lines_from_intermediate_file(std::string file_name, std::shared_ptr<BaseReducer> &reducer_ptr)
          { 
            FILE * file_ptr;
            size_t line_len = 0;
            ssize_t read_ret;
            char * read_line = NULL;
            
            file_ptr = fopen(file_name.c_str(), "r");
            if (file_ptr == NULL)
            {
              std::cout << "ERROR: input file not found" << std::endl;
            }
            while (((read_ret = getline(&read_line, &line_len, file_ptr)) != -1))
            {
              std::string key, val;
              std::string read_line_str(read_line);
              std::stringstream ss(read_line_str);
              ss >> key >> val;
              reducer_ptr->impl_->user_reducer_output[key].push_back(val);
            }
            fclose(file_ptr);
          }
            // The means of communication with the gRPC runtime for an asynchronous
            // server.
            WorkerReq::AsyncService* service_;
            // The producer-consumer queue where for asynchronous server notifications.
            ServerCompletionQueue* cq_;
            // Context for the rpc, allowing to tweak aspects of it such as the use
            // of compression, authentication, as well as to send metadata back to the
            // client.
            ServerContext ctx_;

            // What we get from the client.
            WorkDetails request_;
            // What we send back to the client.
            WorkConfirmation reply_;

            // The means to get back to the client.
            ServerAsyncResponseWriter<WorkConfirmation> responder_;

            // Let's implement a tiny state machine with the following states.
            enum CallStatus { CREATE, PROCESS, FINISH };
            CallStatus status_;  // The current serving state.
        };

        // This can be run in multiple threads if needed.
        void HandleRpcs() {
          // Spawn a new CallData instance to serve new clients.
          new CallData(&service_, cq_.get());
          void* tag;  // uniquely identifies a request.
          bool ok;
          while (true) {
            // Block waiting to read the next event from the completion queue. The
            // event is uniquely identified by its tag, which in this case is the
            // memory address of a CallData instance.
            // The return value of Next should always be checked. This return value
            // tells us whether there is any kind of event or cq_ is shutting down.
            GPR_ASSERT(cq_->Next(&tag, &ok));
            GPR_ASSERT(ok);
            static_cast<CallData*>(tag)->Proceed();
          }
        }

        std::unique_ptr<ServerCompletionQueue> cq_;
        WorkerReq::AsyncService service_;
        std::unique_ptr<Server> server_;
        std::string listening_port;
};


/* CS6210_TASK: ip_addr_port is the only information you get when started.
	You can populate your other class data members here if you want */
Worker::Worker(std::string ip_addr_port) {
  listening_port = ip_addr_port;
}


/* CS6210_TASK: Here you go. once this function is called your woker's job is to keep looking for new tasks 
	from Master, complete when given one and again keep looking for the next one.
	Note that you have the access to BaseMapper's member BaseMapperInternal impl_ and 
	BaseReduer's member BaseReducerInternal impl_ directly, 
	so you can manipulate them however you want when running map/reduce tasks*/


bool Worker::run() {
	ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(listening_port, grpc::InsecureServerCredentials());
    // Register "service_" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *asynchronous* service.
    builder.RegisterService(&service_);
    // Get hold of the completion queue used for the asynchronous communication
    // with the gRPC runtime.
    cq_ = builder.AddCompletionQueue();
    // Finally assemble the server.
    server_ = builder.BuildAndStart();

    // Proceed to the server's main loop.
    HandleRpcs();
}
