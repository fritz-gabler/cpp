#ifndef CURE_HPP
#define CURE_HPP

#include "header.hpp"

class	Cure : public AMateria
{
	public:
		Cure( void );
		Cure( const Cure &other );
		Cure &operator = ( const Cure &other );
		virtual ~Cure( void );

		virtual Cure	*clone( void ) const;
		virtual void	use( ICharacter &target );
};

#endif
