#pragma once
#include<iostream>
#include <string>
#include <vector>
#include<fstream>

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

/* CS6210_TASK: Create your data structure here for storing spec from the config file */
struct MapReduceSpec {
	uint n_workers;
	std::vector<std::string> worker_ipaddr_ports;
	std::vector<std::string> abs_input_files;
	std::string output_dir;
	uint n_output_files;
	uint map_kilobytes;
	std::string user_id;
};


/* CS6210_TASK: Populate MapReduceSpec data structure with the specification from the config file */
inline bool read_mr_spec_from_config_file(const std::string& config_filename, MapReduceSpec& mr_spec) {
	FILE *ifs = fopen(config_filename.c_str(),"r");
	if (ifs == NULL)
	{
	  return false;
	}
	int len=-1, end;
	std::string config_line="";
	std::string val;
	std::string eq = "=";
	std::string comma=",";
	std::string values = "";
	size_t line_len = 0;
    ssize_t read_ret;
	char * read_line = NULL;

	read_ret = getline(&read_line, &line_len, ifs);
	if(read_line[read_ret-1] == '\n')
	{
      read_line[read_ret-1] = '\0';
	}
	config_line = std::string(read_line);
	values = config_line.substr(config_line.find(eq)+eq.length(),std::string::npos); 
	mr_spec.n_workers = stoi(values);
	read_line = NULL;
	read_ret = getline(&read_line, &line_len, ifs);
	if(read_line[read_ret-1] == '\n')
	{
      read_line[read_ret-1] = '\0';
	}
	config_line = std::string(read_line);
	values = config_line.substr(config_line.find(eq)+eq.length(),std::string::npos); 
	end = 0;
	while(end!=std::string::npos){
		end = values.find(comma);
		val = values.substr(0, end); 
		values = values.substr(end+1,std::string::npos);
		mr_spec.worker_ipaddr_ports.push_back(val);
	}
	read_line = NULL;
	read_ret = getline(&read_line, &line_len, ifs);
	if(read_line[read_ret-1] == '\n')
              read_line[read_ret-1] = '\0';
	config_line = std::string(read_line);
	values = config_line.substr(config_line.find(eq)+eq.length(),std::string::npos); 
	end = 0;
	while(end!=std::string::npos){
		end = values.find(comma);
		val = values.substr(0, end); 
		values = values.substr(end+1,std::string::npos);
		mr_spec.abs_input_files.push_back(val);
	}
	read_line = NULL;
	read_ret = getline(&read_line, &line_len, ifs);
	if(read_line[read_ret-1] == '\n')
	{
      read_line[read_ret-1] = '\0';
	}
	config_line = std::string(read_line);
	values = config_line.substr(config_line.find(eq)+eq.length(),std::string::npos); 
	mr_spec.output_dir = values;
	read_line = NULL;
	read_ret = getline(&read_line, &line_len, ifs);
	if(read_line[read_ret-1] == '\n')
	{
      read_line[read_ret-1] = '\0';
	}
	config_line = std::string(read_line);
	values = config_line.substr(config_line.find(eq)+eq.length(),std::string::npos); 
	mr_spec.n_output_files = stoi(values);
	read_line = NULL;
	read_ret = getline(&read_line, &line_len, ifs);
	if(read_line[read_ret-1] == '\n')
	{
      read_line[read_ret-1] = '\0';
	}
	config_line = std::string(read_line);
	values = config_line.substr(config_line.find(eq)+eq.length(),std::string::npos); 
	mr_spec.map_kilobytes = stoi(values);
	read_line = NULL;
	read_ret = getline(&read_line, &line_len, ifs);
	if(read_line[read_ret-1] == '\n')
	{
      read_line[read_ret-1] = '\0';
	}
	config_line = std::string(read_line);
	values = config_line.substr(config_line.find(eq)+eq.length(),std::string::npos); 
	mr_spec.user_id = values;

	return true;
}


/* CS6210_TASK: validate the specification read from the config file */
inline bool validate_mr_spec(const MapReduceSpec& mr_spec) {
	bool ret_val = true;
	
	if ((mr_spec.n_workers > mr_spec.worker_ipaddr_ports.size()) || (mr_spec.n_workers == 0))
	{
	  ret_val = false;
	}
	if ((mr_spec.abs_input_files.size() == 0) || (mr_spec.n_output_files == 0) || (mr_spec.map_kilobytes == 0))
	{
		ret_val = false;
	}

	return ret_val;
}
