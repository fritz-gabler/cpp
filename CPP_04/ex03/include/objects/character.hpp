#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "header.hpp"

class Character : public ICharacter
{

	public:
		Character( void );
		Character( const Character &other );
		Character( const std::string name );
		Character &operator = ( const Character &other );

		virtual const std::string	&getName( void ) const;
		virtual void				equip( AMateria *materia );
		virtual void				unequip( int index );
		virtual void				use( int index, ICharacter &target );

	private:
		void			saveMateria( int index );
		AMateria		*_inventory[INVENTORY_VOLUME];
		AMateria		*_trashBack[INVENTORY_VOLUME];
		int				indexTrashBack;
};

#endif
