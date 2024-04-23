/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:50:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/23 17:52:41 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	getInput(std::string &zombieName, int &numberOfZombies);
static void	announceAllZombies(Zombie *zombie, int numberOfZombies);
static void	getZombieName( std::string &zombieName );
static void	getNumberOfZombies( int &numberOfZombies);
static bool	isStrAlphanumOrdigit( std::string string, bool alphanum, bool digit);

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

	getZombieName(zombieName);
	getNumberOfZombies(numberOfZombies);
}

static void	getZombieName( std::string &zombieName )
{
	bool	runLoop;

	runLoop = true;
	while (runLoop == true)
	{
		std::cout << "Enter a zombie name: ";
		std::getline(std::cin, zombieName);
		if (isStrAlphanumOrdigit(zombieName, true, false) == false)
			std::cout << "Input: " << zombieName << " is not alphanumeric\n";
		else
			runLoop = false;
	}
}


static void	getNumberOfZombies( int &numberOfZombies)
{
	bool					runLoop;
	std::stringstream		strToconvert;
	std::string				numberString;

	runLoop = true;
	while (runLoop == true)
	{
		std::cout << "Enter size of zombie horde: ";
		std::getline(std::cin, numberString);
		if (isStrAlphanumOrdigit(numberString, false, true) == false)
			std::cout << "Input: " << numberString << " is not a digit\n";
		else
			runLoop = false;
	}
	strToconvert << numberString;
	strToconvert >> numberOfZombies;
}

static bool	isStrAlphanumOrdigit( std::string string, bool alphanum, bool digit)
{
	for( int i = 0 ; string[i] != '\0' && alphanum == true; i++)
	{
		if (std::isalnum(string[i]) == false)
			return (false);
	}
	for( int i = 0 ; string[i] != '\0' && digit == true; i++)
	{
		if (std::isdigit(string[i]) == false)
			return (false);
	}
	return (true);
}

static void	announceAllZombies(Zombie *zombie, int numberOfZombies)
{
	for (int i = 0; i < numberOfZombies; i++)
		zombie[i].announce();
}
