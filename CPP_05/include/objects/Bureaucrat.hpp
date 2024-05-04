#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <header.hpp>

class	Bureaucrat
{
	public:
		//Constructor and Destructor
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat( const std::string &name, unsigned int grade );
		Bureaucrat &operator = ( const Bureaucrat &other );
		~Bureaucrat( void );

		//Memberfunctions
		const std::string	&get_name() const;
		unsigned int	get_grade() const;
		void			promote_bureaucrat();
		void			demotion_bureaucrat();

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

std::ostream &operator << (std::ostream &ostream, const Bureaucrat &bureaucrat);
#endif
