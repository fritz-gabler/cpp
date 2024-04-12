#ifndef SAVE_TRAP
#define SAVE_TRAP

#include "header.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const std::string name );
		ScavTrap( const ScavTrap &other );
		ScavTrap &operator = ( const ScavTrap &other );
		~ScavTrap( void );

		void	guardGate( void );
	private:
		bool	_isProtecting;
};

#endif
