#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

# include "header.hpp"

//ERROR
void	errorOccured(const char *errorMessage, Input &input);

//INPUT CHECK
void	inptCheck(Input &input);

//Setup Structs
void	setupStruct(Input &input, int ac, char **av);


#endif
