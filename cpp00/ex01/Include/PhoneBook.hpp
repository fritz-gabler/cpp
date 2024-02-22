#ifndef		PHONE_BOOOK_H
#define		PHONE_BOOOK_H

////////////////////////////////////INCLUDES////////////////////////////////////

# include <iostream>
# include <ostream>
# include <stdio.h>

////////////////////////////////////OBJECTS/////////////////////////////////////

# include "ContactObject.hpp"
# include "PhoneBookObject.hpp"

////////////////////////////////////STRUCTURES//////////////////////////////////

# include "Structures.hpp"

////////////////////////////////////FUNCTIONS///////////////////////////////////

//DISPLAY PROMT
void	HeaderPrint(void);

//INPUT PARSING
void	GetCommand(Process *Process);

//////////////////////////////////////COLORS////////////////////////////////////

# define RED					"\x01\033[1;31m\x02"
# define DARK_GREEN				"\x01\033[1;32m\x02"
# define GRASS_GREEN			"\x01\033[38;2;0;255;0m\x02"
# define YELLOW					"\x01\033[1;33m\x02"
# define MAGENTA				"\x01\033[1;35m\x02"
# define BLUE					"\x01\033[1;34m\x02"
# define WHITE					"\x01\033[0m\x02"
# define ORANGE					"\x01\033[38;2;255;165;0m\x02"
# define RESET					"\033[0m"


#endif
