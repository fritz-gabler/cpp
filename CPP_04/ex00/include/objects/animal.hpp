#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "header.hpp"

class	Animal
{
	public:
		Animal( void );
		Animal( const Animal &other );
		Animal	&operator = ( const Animal &other );
		~Animal( void );

		void	makeSound( void );
	protected:
		std::string		_type;
};

#endif
