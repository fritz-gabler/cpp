#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include "header.hpp"

class	WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal &other );
		WrongAnimal( const std::string type );
		WrongAnimal	&operator = ( const WrongAnimal &other );
		virtual ~WrongAnimal( void );

		void		makeSound( void ) const; 
		std::string	getType( void ) const;
	protected:
		std::string		_type;
};

#endif
