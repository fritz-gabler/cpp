/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:35:10 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/06 13:46:39 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void	grade_too_high();
static void	grade_low_high();

int	main()
{
	try
	{
		std::cout << "\n----------------\n"
					<<"[Try to create a Bueraucrat with a too HIGH grade]\n"; 
		grade_too_high();
	}
	catch(const Bureaucrat::GradeTooHighException &exeption)
	{
		std::cout << "Catched exeption GRADE TOO HIGH\n";
		std::cout << exeption.what() << std::endl;
		std::cout << "----------------\n";
	}
	catch(const std::exception &exeption)
	{
		std::cout << "Catched exeption GRADE TOO HIGH\n";
		std::cout << exeption.what() << std::endl;
		std::cout << "----------------\n";
		//Just for the subject;
	}
	try
	{
		std::cout << "\n----------------\n"
					<<"[Try to create a Bueraucrat with a too LOW grade]\n"; 
		grade_low_high();
	}
	catch(const Bureaucrat::GradeTooLowException &exeption)
	{
		std::cout << "Catched exeption GRADE TOO LOW\n";
		std::cout << exeption.what() << std::endl;
		std::cout << "----------------\n";
	}
	catch(const std::exception &exeption)
	{
		std::cout << "Catched exeption GRADE TOO HIGH\n";
		std::cout << exeption.what() << std::endl;
		std::cout << "----------------\n";
		//Just for the subject;
	}

	return (false);
}

static void	grade_too_high()
{
	Bureaucrat grade_too_high("To high Grade", 151);
}

static void	grade_low_high()
{
	Bureaucrat grade_too_low("To low Grade", 0);
}
