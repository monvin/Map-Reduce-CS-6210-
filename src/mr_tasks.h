#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>

/* CS6210_TASK Implement this data structureas per your implementation.
		You will need this when your worker is running the map task*/
struct BaseMapperInternal {

		/* DON'T change this function's signature */
		BaseMapperInternal();

		/* DON'T change this function's signature */
		void emit(const std::string& key, const std::string& val);

		/* NOW you can add below, data members and member functions as per the need of your implementation*/
		std::string cur_user_id;
		std::vector<FILE *> intermediate_file_vec;
		long intermediate_file_count;
};


/* CS6210_TASK Implement this function */
inline BaseMapperInternal::BaseMapperInternal() {

}


/* CS6210_TASK Implement this function */
inline void BaseMapperInternal::emit(const std::string& key, const std::string& val) {
	long char_sum = 0;
	long file_index;

	for (int i = 0; i < key.length(); i++)
	{
		char_sum += key[i];
	}
    file_index = char_sum % intermediate_file_count;
	fprintf(intermediate_file_vec[file_index], "%s %s\n", key.c_str(), val.c_str());
	//std::cout << "Dummy emit by BaseMapperInternal: " << key << ", " << val << std::endl;
}


/*-----------------------------------------------------------------------------------------------*/


/* CS6210_TASK Implement this data structureas per your implementation.
		You will need this when your worker is running the reduce task*/
struct BaseReducerInternal {

		/* DON'T change this function's signature */
		BaseReducerInternal();

		/* DON'T change this function's signature */
		void emit(const std::string& key, const std::string& val);

		/* NOW you can add below, data members and member functions as per the need of your implementation*/
		std::map<std::string, std::vector<std::string> > user_reducer_output;
		FILE *f_ptr;
};


/* CS6210_TASK Implement this function */
inline BaseReducerInternal::BaseReducerInternal() {

}


/* CS6210_TASK Implement this function */
inline void BaseReducerInternal::emit(const std::string& key, const std::string& val) {
	fprintf(f_ptr, "%s %s\n", key.c_str(), val.c_str());
}
