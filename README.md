# Design
- gRPC framework for master-worker communication is set up by adapting the example https://github.com/grpc/grpc/tree/master/examples/cpp/helloworld
- Master communicates with workers asynchronously. Dedicated threads are created to receive responses from each worker
- A job id is assigned to each mapper/reducer task. The ID is used to create unique file names as well as to identify slow/dead workers
- Number of reducer workers is communicated with mapper workers. This information helps mapper to name intermediate files and to assign a key to a reducer
- Number of intermediate files created by a mapper worker is equal to the number of reducer workers. i.e. a mapper worker would have an intermediate file dedicated to each reducer worker
- Intermediate file name created by mapper worker comprises of both mapper job id and index of reducer for which the intermediate file is targeted for
- RPC message sent to reducer would comprise of completed mapper job IDs. This allows reducer worker to construct intermediate file names
- Each key value is assigned to a reducer. A key is associated with a reducer by the relation reducer_index = (sum of ASCII values of character values in the key % number of reducer workers). Mapper worker identifies the appropriate intermediate file for a 'key, value' pair using this relation

# Handling slow worker and worker failure
Master maintains a database with job details and tracks the workers assigned to finish each job. The database helps the master to identify free workers to assign the next job to. As per design all the mapper jobs are scheduled first. Then the master waits until all the mapper jobs are completed. Subsequently all the reducer jobs are scheduled and the master waits for their completion. Since map and reduce operations follow job issue and wait sequence, master uses the same approach (given below) to identify slow/failed workers during both phases
- Assign all the jobs to next available thread one after the other
- Once all the jobs are issued, check if all jobs are completed, in intervals of 100 milliseconds. Continue checking for a maximum duration of WAIT_PERIOD. This is the checkpoint to start re-assigning jobs.
- After WAIT_PERIOD, assign each incomplete job to the next available worker using a new job ID. When all the incomplete jobs are re-assigned, check for their completion in intervals of 100 milliseconds for a maximum duration of WAIT_PERIOD
- Repeat the above step until all the jobs are completed
- WAIT_PERIOD is a configuration parameter, which is currently configured as 5 sec to prevent very long jobs to be mistaken as slow job
- Any mapper job completed before the checkpoint by a dead or slow worker is not re-assigned as the intermediate files corresponding to them are available in the file system. Any intermediate files created by a slow mapper after the checkpoint are ignored by the master. Any output file created by a slow reducer after the checkpoint is to be discarded. Master has the information of correct output files and can be shared with any other application as needed
