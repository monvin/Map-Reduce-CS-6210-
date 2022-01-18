#include <iostream>

#include "mapreduce_impl.h"
#include "master.h"

enum Activity_State{IDLE, BUSY, READY};
typedef struct job_details
{
  Activity_State state;
  unsigned int worker_id;
  unsigned int job_id;
}job_details_t;

std::vector<Activity_State> worker_register;
std::vector<job_details_t> job_register;
unsigned int max_job_count;
unsigned int completed_job_count;

pthread_mutex_t database_lock = PTHREAD_MUTEX_INITIALIZER;

void database_init(unsigned int worker_count, unsigned int job_count)
{
  worker_register.resize(worker_count, IDLE);
  job_register.resize(job_count);
  for (int i = 0; i < job_count; i++)
  {
      job_register[i].state = IDLE;
      job_register[i].worker_id = -1;
      job_register[i].job_id = -1;
  }
}

void database_reset(void)
{
    pthread_mutex_lock(&database_lock);
    for (int i = 0; i < job_register.size(); i++)
    {
      job_register[i].state = IDLE;
      job_register[i].worker_id = -1;
      job_register[i].job_id = -1;
    }
    pthread_mutex_unlock(&database_lock);
}

int get_free_worker_id(void)
{
    int ret_val = -1;
    int i;
    pthread_mutex_lock(&database_lock);
    for (i = 0; i < worker_register.size(); i++)
    {
        if(worker_register[i] == IDLE)
        {
            break;
        }
    }
    pthread_mutex_unlock(&database_lock);
    if (i < worker_register.size())
    {
        ret_val = i;
    }

    return ret_val;
}

void set_max_job_count(unsigned int count)
{
  pthread_mutex_lock(&database_lock);
  max_job_count = count;
  completed_job_count = 0;
  pthread_mutex_unlock(&database_lock);
}

void start_job(unsigned int worker_id, unsigned int job_id)
{
  pthread_mutex_lock(&database_lock);
  worker_register[worker_id] = BUSY;
  job_register[job_id % max_job_count].state = BUSY;
  job_register[job_id % max_job_count].worker_id = worker_id;
  job_register[job_id % max_job_count].job_id = job_id;
  pthread_mutex_unlock(&database_lock);
}

bool is_job_completed(unsigned int job_id)
{
    bool ret_val = false;

    pthread_mutex_lock(&database_lock);
    if (job_register[job_id % max_job_count].state == READY)
    {
        ret_val = true;
    }
    pthread_mutex_unlock(&database_lock);

    return ret_val;
}
void finish_job(unsigned int worker_id, unsigned int job_id)
{
     pthread_mutex_lock(&database_lock);
     if ((job_register[job_id % max_job_count].job_id == job_id) && (job_register[job_id % max_job_count].worker_id == worker_id))
     {
         worker_register[worker_id] = IDLE;
         job_register[job_id % max_job_count].state = READY;
         completed_job_count++;
     }
     else
     {
         worker_register[worker_id] = IDLE;
     }
     pthread_mutex_unlock(&database_lock);
}

void dump_job_details(void)
{
    for (int i = 0; i < max_job_count; i++)
    {
      std::cout << "JOB " << i << ": " << job_register[i].state << ", " << job_register[i].worker_id << ", " << job_register[i].job_id << std::endl;
    }
}

unsigned int get_job_id_from_index(unsigned int index)
{
  unsigned int ret_val;

  pthread_mutex_lock(&database_lock);
  ret_val = job_register[index].job_id;
  pthread_mutex_unlock(&database_lock);

  return ret_val;
}

bool is_task_pending(void)
{
    bool ret_val;

    pthread_mutex_lock(&database_lock);
    if (completed_job_count == max_job_count)
    {
        ret_val = false;
    }
    else
    {
        ret_val = true;
    }
    pthread_mutex_unlock(&database_lock);

    return ret_val;
}

/* DON'T touch this function */
bool MapReduceImpl::run(const std::string& config_filename) {
    
    if(!read_and_validate_spec(config_filename)) {
        std::cerr << "Spec not configured properly." << std::endl;
        return false;
    }
    if(!create_shards()) {
        std::cerr << "Failed to create shards." << std::endl;
        return false;
    }

    if(!run_master()) {
        std::cerr << "MapReduce failure. Something didn't go well!" << std::endl;
        return false;
    }

    return true;
}


/* DON'T touch this function */
bool MapReduceImpl::read_and_validate_spec(const std::string& config_filename) {
    return read_mr_spec_from_config_file(config_filename, mr_spec_) && validate_mr_spec(mr_spec_);
}


/* DON'T touch this function */
bool MapReduceImpl::create_shards() {
    return shard_files(mr_spec_, file_shards_);
}


/* DON'T touch this function */
bool MapReduceImpl::run_master() {
    Master master(mr_spec_, file_shards_);
    return master.run();
}
