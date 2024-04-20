#ifndef ICE_HPP
#define ICE_HPP

#include "header.hpp"

class	Ice : public AMateria
{
	public:
		Ice( void );
		Ice( const Ice &other );
		Ice &operator = ( const Ice &other );
		virtual ~Ice( void );

		virtual Ice		*clone( void ) const;
		virtual void	use( ICharacter &target );
};

#endif
