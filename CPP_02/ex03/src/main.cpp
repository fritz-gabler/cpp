/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:55:34 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/09 10:37:33 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main( void )
{
	Point	Apoint(0, 2);
	Point	Bpoint(8, 2);
	Point	Cpoint(6, 8);

	Point	checkPointOne(2.5f, 3.0);
	if (bsp(Apoint, Bpoint, Cpoint, checkPointOne) == true)
		std::cout << "point is in range of triangle" << std::endl;
	else
		std::cout << "point is NOT in range of triangle" << std::endl;
	return 0;
}

