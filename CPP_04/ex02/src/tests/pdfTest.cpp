/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdfTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:37:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/19 09:58:39 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	pdfTest( void )
{
	std::cout << "\n------------------PDF TEST------------------\n";
	//const AbstractAnimal thatWillNotWork;
	const AbstractAnimal* dogPtr = new Dog();
	const AbstractAnimal* Catptr = new Cat();

	std::cout << std::endl;

	delete dogPtr;
	delete Catptr;
	std::cout << std::endl;
}
