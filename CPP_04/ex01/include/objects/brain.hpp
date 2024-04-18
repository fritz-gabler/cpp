#ifndef BRAIN_HPP
#define  BRAIN_HPP

#include "header.hpp"

class	Brain
{
	public:
		Brain( void );
		Brain( const Brain &other );
		Brain &operator = ( const Brain &other );
		~Brain( void );
	private:
		std::string	_ideas[100];
};

#endif
