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
		virtual const std::string	&getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

	private:
		std::string	_name;
};


#endif
