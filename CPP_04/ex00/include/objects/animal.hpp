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

		virtual void		makeSound( void ) const; 
		std::string	getType( void ) const;
	protected:
		std::string		_type;
};

#endif
