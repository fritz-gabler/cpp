/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:50:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/08 14:24:47 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	getInput(std::string &zombieName, int &numberOfZombies);
static void	announceAllZombies(Zombie *zombie, int numberOfZombies);

int	main(void)
{
	std::string	zombieName;
	int			numberOfZombies;
	Zombie		*saveZombie;


	getInput(zombieName, numberOfZombies);
	saveZombie = zombieHorde(numberOfZombies, zombieName);
	announceAllZombies(saveZombie, numberOfZombies);
	delete [] saveZombie;
}

static void	getInput(std::string &zombieName, int &numberOfZombies)
{
	std::cout << "Enter a zombie name: ";
	std::getline(std::cin, zombieName);
	std::cout << "Enter size of zombie horde: ";
	std::cin >> numberOfZombies;
	std::cin.ignore();
}

static void	announceAllZombies(Zombie *zombie, int numberOfZombies)
{
	for (int i = 0; i < numberOfZombies; i++)
		zombie[i].announce();
}
