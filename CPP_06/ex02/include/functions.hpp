#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include "define.hpp"
#include "Base.hpp"

//LOG
void log(std::string message, t_log_level level);

//GENERATE TYPE
Base *generate(void);

//IDENTYFY REAL TYPE
void identify(Base *p);
void identify(Base &p);

#endif

