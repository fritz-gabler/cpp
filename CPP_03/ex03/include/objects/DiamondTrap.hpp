#ifndef	DIMOND_TRAP_HPP
#define	DIMOND_TRAP_HPP

#include "header.hpp"

class	DiamondTrap : public ClapTrap ,FragTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap ( const std::string name);
		DiamondTrap &operator = ( const DiamondTrap &other );
		~DiamondTrap( void );

		void	attack( const std::string &target);
		void	whoAmI( void );
	private:
		std::string	_name;
};

#endif
