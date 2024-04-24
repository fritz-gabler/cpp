/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:32:56 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/24 09:03:07 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void TriangleCalc(Point const a, Point const b, Point const c, Fixed &area);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaOrginal;
	Fixed	partOfTriangle[3];
	Fixed	compareArea;

	TriangleCalc(a, b, c, areaOrginal);
	TriangleCalc(a, b, point, partOfTriangle[A]);
	TriangleCalc(a, c, point, partOfTriangle[B]);
	TriangleCalc(b, c, point, partOfTriangle[C]);
	compareArea = partOfTriangle[A] + partOfTriangle[B] + partOfTriangle[C];
	if (compareArea == areaOrginal)
		return (true);
	return (false);
}

static void TriangleCalc(Point const a, Point const b, Point const c, Fixed &area)
{
	area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	if (area > 0)
		area = area / 2;
	else
		area = (area * (-1)) / 2;
}
