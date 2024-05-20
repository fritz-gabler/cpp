#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "define.hpp"

//Input parsing
bool input_check(int ac);



//Log
void log(std::string message, t_log_level level);

//String check
bool is_str_convertible_to_int(const std::string &str);
#endif

