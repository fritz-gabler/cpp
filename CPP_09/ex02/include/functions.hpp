#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "define.hpp"
#include <string>
#include <time.h>

//LOG
void log(std::string message, t_log_level level);

//INPUT
bool input_validation(char **av, int ac);

//CONVERT
void convert_input(int ac, char **av, std::vector<unsigned int> &converted_input);

//TIME
void start_time(clock_t &time);
void get_stopped_time(clock_t &time, double &duration);
void start_time(time_t &time);
void get_stopped_time(time_t &time, double &duration);



#endif

