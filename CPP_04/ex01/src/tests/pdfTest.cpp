/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdfTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:37:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/18 19:38:35 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	pdfTest( void )
{
	std::cout << "\n------------------PDF TEST------------------\n";
	const Animal* dogPtr = new Dog();
	const Animal* Catptr = new Cat();

	std::cout << std::endl;

	delete dogPtr;
	delete Catptr;
	std::cout << std::endl;
}
