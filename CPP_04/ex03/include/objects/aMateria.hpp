#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include "header.hpp"

class	AMateria
{
	public:
		AMateria( void );
		AMateria( const std::string & type );
		AMateria( const AMateria &other );
		AMateria &operator = ( const AMateria &other );

		const std::string	&getType( void ) const;
		virtual AMateria	*clone( void ) const = 0;
		virtual void		use(ICharacter& target);
	private:
		std::string	_type;
};

#endif
