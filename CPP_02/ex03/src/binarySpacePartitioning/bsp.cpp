/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:32:56 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/08 18:51:38 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void	calcLineBetweenTwoPoints(Point const one, Point const two, float &line);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	aLine;
	float	bLine;
	float	cLine;

	calcLineBetweenTwoPoints(a, b, aLine);
	calcLineBetweenTwoPoints(c, b, bLine);
	calcLineBetweenTwoPoints(a, c, cLine);
	std::cout << "Line a: " << aLine << std::endl;
	std::cout << "Line b: " << bLine << std::endl;
	std::cout << "Line c: " << cLine << std::endl;
	(void) point;
	(void) c;
	return (true);
}

static void	calcLineBetweenTwoPoints(Point const one, Point const two, float &line)
{
	line = std::pow(2, one.getX().toFloat() - two.getX().toFloat()) + std::pow(2, one.getY().toFloat() - two.getY().toFloat());
	line = std::sqrt(line);
}
