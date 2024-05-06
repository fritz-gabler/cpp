#ifndef FORM_HPP
#define FORM_HPP

#include "header.hpp"

class	Form
{
	public:
		Form();
		Form( const Form &other );
		Form &operator = ( const Form &form );
		~Form();

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	name_;
		bool				is_signed_;
		const int			grade_required_to_signed_;

};

std::ostream &operator << (std::ostream &ostream, const Form &form);
#endif
