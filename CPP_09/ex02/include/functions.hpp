#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "define.hpp"
#include <string>

//LOG
void log(std::string message, t_log_level level);

//INPUT
bool input_validation(char **av, int ac);




//CONVERT
void convert_input(int ac, char **av,
                              std::vector<unsigned int> &converted_input);

#endif

