#ifndef DOG_HPP
#define DOG_HPP

#include "header.hpp"

class	Dog : public Animal
{
	public:
		Dog( void );
		Dog( const Dog &other );
		Dog &operator = ( const Dog &other );
		~Dog( void );

		virtual void makeSound() const;
		void			saveNewIdea( const std::string &idea );
		void			changeAnIdea( const std::string &idea, int ideaNumber );
		void			printIdeas( void );
		void			printAnSpecificIdea( int ideaNumber );

	private:
		Brain	*_brain;
};

#endif
