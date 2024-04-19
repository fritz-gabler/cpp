#ifndef CAT_HPP
#define CAT_HPP

#include "header.hpp"

class	Cat : public AbstractAnimal
{
	public:
		Cat( void );
		Cat( const Cat &other );
		Cat &operator = (const Cat &other );
		~Cat( void );

		virtual void	makeSound( void ) const;
		void			saveNewIdea( const std::string &idea );
		void			changeAnIdea( const std::string &idea, int ideaNumber );
		void			printIdeas( void ) const;
		void			printAnSpecificIdea( int ideaNumber );
	private:
		Brain	*_brain;
};

#endif
