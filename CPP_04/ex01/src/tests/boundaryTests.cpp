/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaryTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:39:05 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/18 19:46:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void	catBoundaryTests( void );
static void	dogBoundaryTests( void );

void	boundaryTests( void )
{
	std::cout << "\n------------------BOUNDARY TEST------------------\n";
	catBoundaryTests();
	dogBoundaryTests();
}

static void	catBoundaryTests( void )
{
	Cat	littleCat;

	std::cout << std::endl;
	littleCat.saveNewIdea("first little Cat idea");
	littleCat.printAnSpecificIdea(0);
	for (int i = 0; i < (BRAIN_CAPACITY - 1) ; i++)
		littleCat.saveNewIdea("An usless idea");
	littleCat.saveNewIdea("last little Cat idea");
	littleCat.printAnSpecificIdea(0);
	std::cout << std::endl;
}

static void	dogBoundaryTests( void )
{
	Dog	littleDog;

	std::cout << std::endl;
	littleDog.saveNewIdea("first little Cat idea");
	littleDog.printAnSpecificIdea(0);
	for (int i = 0; i < (BRAIN_CAPACITY - 1) ; i++)
		littleDog.saveNewIdea("An usless idea");
	littleDog.saveNewIdea("last little Cat idea");
	littleDog.printAnSpecificIdea(0);
	std::cout << std::endl;
}
