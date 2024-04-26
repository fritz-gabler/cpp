#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "header.hpp"

class	AbstractAnimal
{
	public:
		AbstractAnimal( void );
		AbstractAnimal( const AbstractAnimal &other );
		AbstractAnimal( const std::string type );
		AbstractAnimal	&operator = ( const AbstractAnimal &other );
		virtual ~AbstractAnimal( void );

		virtual void		makeSound( void ) const = 0;
		std::string			getType( void ) const;
	protected:
		std::string		_type;
};

#endif
