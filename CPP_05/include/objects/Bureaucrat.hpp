#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <header.hpp>

class	Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat &operator = ( const Bureaucrat &other );
		~Bureaucrat( void );

	private:
		const std::string	name_;
		unsigned int		grade_;

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator << (std::ostream &ostream, const Bureaucrat &bureaucrat)
#endif
