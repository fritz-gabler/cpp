/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:44:11 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/08 10:15:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie		*HeapZombie;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "         Allocate a zombie on the heap       " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	HeapZombie = newZombie("HeapZombieOne");
	HeapZombie->announce();
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "         Delete zombie from the heap        " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	delete HeapZombie;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "         Create a zombie on the stack        " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	randomChump("StackZombie");
	return (0);
}
