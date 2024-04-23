/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiaTest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:42:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/23 14:12:19 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"


void	materiaTest( void )
{
	std::cout << "\n------------------MATERIA TEST------------------\n";
	MateriaSource materia;


	std::cout << "\nTry to learn more than four materials:\n";
	for (int i = 0 ; i <= INVENTORY_VOLUME ; i++ )
	{
		std::cout << "i: " << i << " | ";
		if (i == 4)
			std::cout << std::endl;
		materia.learnMateria(new Cure());
	}
	std::cout << std::endl;

	std::cout << "\nTry to create materia ice:\n";
	materia.createMateria("ice");
	std::cout << std::endl;
}
