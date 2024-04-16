#ifndef DOG_HPP
#define DOG_HPP

#include "header.hpp"

class	Dog : public Animal
{
	public:
		Dog( void );
		Dog( const Dog &other );
		Dog &operator = ( const Dog &other );
		~Dog( void );
};

#endif
