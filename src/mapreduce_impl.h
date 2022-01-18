#pragma once

#include "mapreduce_spec.h"
#include "file_shard.h"


class MapReduceImpl {
	
	public:
		/* DON'T change this function declaration */
		bool run(const std::string& config_filename);

	private:
		/* DON'T change the function declaration for these three functions */
		bool read_and_validate_spec(const std::string& config_filename);
		bool create_shards();
		bool run_master();

		MapReduceSpec mr_spec_;
		std::vector<FileShard> file_shards_;

};

void database_init(unsigned int worker_cout, unsigned int job_count);
void database_reset(void);
int get_free_worker_id(void);
void set_max_job_count(unsigned int count);
void start_job(unsigned int worker_id, unsigned int job_id);
void finish_job(unsigned int worker_id, unsigned int job_id);
void dump_job_details(void);
unsigned int get_job_id_from_index(unsigned int index);
bool is_task_pending(void);
bool is_job_completed(unsigned int job_id);