#ifndef		HEADER_HPP
#define		HEADER_HPP

////////////////////////////////////INCLUDES////////////////////////////////////

# include <iostream>
# include <ostream>
# include <stdio.h>
# include <iomanip>
#include <sstream>

////////////////////////////////////OBJECTS/////////////////////////////////////

# include "Contact.hpp"
# include "PhoneBook.hpp"

////////////////////////////////////STRUCTURES//////////////////////////////////

# include "Structures.hpp"

////////////////////////////////////FUNCTIONS///////////////////////////////////

//DISPLAY PROMT
void	HeaderPrint(void);
void	ResetPromt(Process *Process);

//INPUT PARSING
void	GetCommand(Process *Process);
int		IsString(std::string str);
void	SetAction(PhoneBook *PhoneBook, Process *Process);
bool	ValidePhoneNumber(std::string PhoneNumber);
bool	ContactExist(int NumberOfContacts);

//Process Functions
void	ResetProcess(Process *Process);
void	SetProcess(Process *Process);

//Methods
void	DisplayFeeldStr(std::string Content);
void	DisplayFeeldInt(int Content);
void	WaitTillInput(int &LinesPrinted);

//Search contact
bool	isValidContactNumber(int input, int numberOfContacts);
void	convertStringToInt(std::string string, int &convertedString);

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
# define UP						"\033[A"
# define CUT					"\033[K"

//////////////////////////////////////STRINGS////////////////////////////////////

# define NEW_CONTACT			"You'r adding a new contact. Enter the following fields\n";
# define WRONG_NUMBER			"Wrong input, Number needs to start with + or 0.\nNumber can't be longer than 15 or shorter that 7 digits\n";
# define NO_CONTACT				"Please add a contact before you try to display one\n";

#endif
