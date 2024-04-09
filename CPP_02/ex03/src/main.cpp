/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:55:34 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/09 17:17:38 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main( void )
{
	Point	Apoint(0, 0);
	Point	Bpoint(10, 0);
	Point	Cpoint(6, 8);

	Point	checkPointOne(2.4f, 2.9);
	if (bsp(Apoint, Bpoint, Cpoint, checkPointOne) == true)
		std::cout << "point is in range of triangle" << std::endl;
	else
		std::cout << "point is NOT in range of triangle" << std::endl;
	return 0;
}

