#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "define.hpp"
#include <string>
#include <sys/time.h>
#include <vector>

//LOG
void log(std::string message, t_log_level level);
void vector_log(std::vector<unsigned int> sequence,
                           std::vector<unsigned int> input, double duration);

//INPUT
bool input_validation(char **av, int ac);

//CONVERT
void convert_input(int ac, char **av, std::vector<unsigned int> &converted_input);

//TIME
void start_time(time_t &time);
void get_stopped_time(time_t &time, double &duration);

//TESTS
void deque_check(std::vector<unsigned int> &input);
void vector_check(std::vector<unsigned int> &input);


#endif

