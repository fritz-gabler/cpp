/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:04:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/17 21:09:06 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main( void )
{
	const Animal		*meta = new Animal();
	const Animal		*dogAnimalPtr = new Dog();
	const Animal		*catAnimalPrt = new Cat();
	const WrongAnimal	*wrongMeta = new Animal();
	const WrongAnimal	*wrongDogAnimalPtr = new Dog();
	const WrongAnimal	*wrongCatAnimalPrt = new Cat();

	std::cout << catAnimalPrt->getType() << " " << std::endl;
	std::cout << dogAnimalPtr->getType() << " " << std::endl;
	catAnimalPrt->makeSound();
	dogAnimalPtr->makeSound();
	meta->makeSound();

	std::cout << wrongCatAnimalPrt->getType() << " " << std::endl;
	std::cout << wrongDogAnimalPtr->getType() << " " << std::endl;
	wrongCatAnimalPrt->makeSound();
	wrongDogAnimalPtr->makeSound();
	wrongMeta->makeSound();

	delete meta;
	delete catAnimalPrt;
	delete dogAnimalPtr;

	delete wrongMeta;
	delete wrongCatAnimalPrt;
	delete wrongDogAnimalPtr;
	return 0;
}

