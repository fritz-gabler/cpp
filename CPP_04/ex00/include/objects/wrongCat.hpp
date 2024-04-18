#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "header.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( const WrongCat &other );
		WrongCat	&operator = ( const WrongCat &other );
		~WrongCat( void );

		void		makeSound( void ) const; 
		std::string	getType( void ) const;
	protected:
		std::string		_type;
};

#endif
