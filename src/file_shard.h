#pragma once
#include <utility>
#include <vector>
#include "mapreduce_spec.h"
#include <stdio.h>


/* CS6210_TASK: Create your own data structure here, where you can hold information about file splits,
     that your master would use for its own bookkeeping and to convey the tasks to the workers for mapping */
struct FileShard {
     unsigned int start;
     std::vector<std::string> input_files;
     std::vector<int> files_offset;
};


/* CS6210_TASK: Create fileshards from the list of input files, map_kilobytes etc. using mr_spec you populated  */ 
inline bool shard_files(const MapReduceSpec& mr_spec, std::vector<FileShard>& fileShards) {
	const uint kb = 1024;
     int file_iter = 0;
     int start = 0;
     int offset = -1;
     long long shard_size_left = mr_spec.map_kilobytes*kb;
     int number_files = mr_spec.abs_input_files.size();
     int number_shards = 0;
	 
     while(file_iter < number_files){
          struct FileShard file_shard = {0};
          file_shard.start = start;
          shard_size_left =  mr_spec.map_kilobytes*kb;
          while(shard_size_left > 0 && file_iter < number_files){
               FILE * fin;
               std::string file = mr_spec.abs_input_files[file_iter];
               fin = fopen(file.c_str(),"r");
               if (fin == NULL)
               {
                    std::cout << "input file is NULL " << file << std::endl;
                    return false;
               }
               fseek (fin, 0, SEEK_END);
               long long unsigned file_size_left = ftell(fin) - start;
               if(shard_size_left >= file_size_left){
					offset = file_size_left;
                    start = 0;
                    file_shard.input_files.push_back(file); 
                    file_shard.files_offset.push_back(offset);
                    shard_size_left -= file_size_left;
                    file_iter++;
               }
               else{
                    fseek(fin, start + shard_size_left - 1, 0);
                    char c;
                    while((c = getc(fin))&&c!=EOF&&c!='\n');
                    if(c!=EOF){
                         offset = ftell(fin) - start;
                         start += offset;
						 offset = offset - 1;
                         file_shard.input_files.push_back(file); 
                         file_shard.files_offset.push_back(offset);
                         shard_size_left = 0;
                    }
                    else{
                         shard_size_left = file_size_left;
                    }
               }
          }
          fileShards.push_back(file_shard);
     }
	 
     return true;
}
