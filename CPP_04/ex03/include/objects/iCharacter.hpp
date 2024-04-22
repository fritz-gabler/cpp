#ifndef I_CHARACTER
#define I_CHARACTER

#include "header.hpp"

class ICharacter
{
	public:
		ICharacter( void );
		ICharacter( const ICharacter &other );
		ICharacter &operator = ( const ICharacter &other );
		virtual ~ICharacter() {}

		virtual const std::string	&getName( void ) const = 0;
		virtual void				equip(AMateria* materia) = 0;
		virtual void				unequip(int index) = 0;
		virtual void				use(int index, ICharacter& target) = 0;

	protected:
		std::string	_name;
};


#endif
