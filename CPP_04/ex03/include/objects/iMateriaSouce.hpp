#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP

#include "header.hpp"

class IMateriaSource
{
	public:
		IMateriaSource( void );
		IMateriaSource( const IMateriaSource &other );
		IMateriaSource &operator = ( const IMateriaSource &other );

		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(const std::string &type) = 0;

};

#endif
