#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

#include "header.hpp"

class	WrongDog : public WrongAnimal
{
	public:
		WrongDog( void );
		WrongDog( const WrongDog &other );
		WrongDog &operator = ( const WrongDog &other );
		virtual ~WrongDog( void );

		void makeSound() const;
};

#endif
