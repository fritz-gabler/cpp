/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/08 16:07:41 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		brainString;
	std::string		*stringPTR;
	std::string		&stringRef = brainString;

	brainString = "HI THIS IS BRAIN";
	stringPTR = &brainString;
	std::cout
			<< "The memory address of the string variable: "
			<< &brainString
			<< std::endl
			<< "The memory address held by stringPTR: "
			<< stringPTR
			<< std::endl
			<< "The memory address held by stringREF: "
			<< &stringRef
			<< std::endl
			<< "And than:"
			<< std::endl
			<< "The value of the string variable: "
			<< brainString
			<< std::endl
			<< "The value pointed to by stringPTR: "
			<< *stringPTR
			<< std::endl
			<< "The value pointed to by stringREF: "
			<< stringRef
			<< std::endl;
	return (0);
}
