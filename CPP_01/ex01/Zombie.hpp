#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////INCLUDES////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////CLASSES/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class	Zombie
{

	public:
						Zombie( void );
						Zombie( std::string NewZombieName);
						~Zombie( void );
		void			announce( void );
		void			set_name(std::string name);
	private:
		std::string		_name;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////FUNCTIONS///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Zombie	*zombieHorde(int N, std::string name);


#endif
