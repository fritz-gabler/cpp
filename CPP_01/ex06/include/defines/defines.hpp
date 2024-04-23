#ifndef DEFINE_HPP
#define DEFINE_HPP

#include "header.hpp"

//ENUMS

enum	ElevelCheck
{
	sameLevel	=	0
};

enum	EcaseLevel
{
	DEBUG		=	0,
	INFO		=	1,
	WARNING		=	2,
	ERROR		=	3
};

//STRING DEFINE

# define	DEBUG_MESSAGE		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define	INFO_MESSAGE		"cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define	WARNING_MESSAGE		"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month"
# define	ERROR_MESSAGE		"This is unacceptable! I want to speak to the manager now."
# define	DEFAULT_MESSAGE		"[ Probably complaining about insignificant problems ]"

#define		WRONG_NB_OF_ARGS	"Wrong number of arguments. Please input DEBUG, INFO, WARNING or ERROR"
#define		WRONG_LEVEL_NAME	"Wrong Level Name, input DEBUG, INFO, WARNING or ERROR"

#endif
