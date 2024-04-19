#ifndef BRAIN_HPP
#define  BRAIN_HPP

#include "header.hpp"

#define BRAIN_CAPACITY 100

class	Brain
{
	public:
		Brain( void );
		Brain( const Brain &other );
		Brain &operator = ( const Brain &other );
		~Brain( void );

		void	saveNewIdea( const std::string &idea );
		void	changeAnIdea( const std::string &idea, int ideaNumber );
		void	printIdeas( void );
		void	printAnSpecificIdea( int ideaNumber );
	private:
		int			_currentIdeaNumber;
		std::string	_ideas[BRAIN_CAPACITY];
};

#endif
