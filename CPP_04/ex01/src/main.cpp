/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:04:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/18 11:15:57 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main( void )
{
	std::cout << "\n\n-------------------ANIMAL-------------------\n\n";
	const Animal		*meta = new Animal();
	const Animal		*dogAnimalPtr = new Dog();
	const Animal		*catAnimalPrt = new Cat();

	std::cout << "\n";
	std::cout << catAnimalPrt->getType() << " " << std::endl;
	std::cout << dogAnimalPtr->getType() << " " << std::endl;
	std::cout << "\n";

	catAnimalPrt->makeSound();
	dogAnimalPtr->makeSound();
	meta->makeSound();
	std::cout << "\n";

	delete meta;
	delete catAnimalPrt;
	delete dogAnimalPtr;

	std::cout << "\n\n-------------------WRONG ANIMAL-------------------\n\n" << std::endl;
	const WrongAnimal	*wrongMeta = new WrongAnimal();
	const WrongAnimal	*wrongCatAnimalPrt = new WrongCat();
	const WrongAnimal	*wrongDogAnimalPtr = new WrongDog();
	std::cout << "\n";

	std::cout << wrongCatAnimalPrt->getType() << " " << std::endl;
	std::cout << wrongDogAnimalPtr->getType() << " " << std::endl;
	std::cout << "\n";

	wrongCatAnimalPrt->makeSound();
	wrongDogAnimalPtr->makeSound();
	wrongMeta->makeSound();
	std::cout << "\n";


	delete wrongMeta;
	delete wrongCatAnimalPrt;
	delete wrongDogAnimalPtr;
	return 0;
}

