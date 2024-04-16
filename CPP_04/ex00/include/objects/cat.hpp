#ifndef CAT_HPP
#define CAT_HPP

#include "header.hpp"

class	Cat
{
	public:
		Cat( void );
		Cat( const Cat &other );
		Cat &operator = (const Animal &other );
		~Cat( void );
};

#endif
