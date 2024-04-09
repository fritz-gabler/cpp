/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:32:56 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/09 10:54:57 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void TriangleCalc(Point const a, Point const b, Point const c, float &area);
static void	calcLineBetweenTwoPoints(Point const one, Point const two, float &line);
static void calcAreaOfTriangle(float line[3], float &area);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	areaOrginal;
	float	partOfTriangle[3];
	float	areaToCheck;
	float	epsilon;

	TriangleCalc(a, b, c, areaOrginal);
	TriangleCalc(a, b, point, partOfTriangle[A]);
	TriangleCalc(a, c, point, partOfTriangle[B]);
	TriangleCalc(b, c, point, partOfTriangle[C]);

	epsilon = std::numeric_limits<float>::epsilon();
	areaToCheck = partOfTriangle[A] + partOfTriangle[B] + partOfTriangle[C];
	if (areaOrginal - areaToCheck < epsilon)
		return (true);
	return (false);
}

static void TriangleCalc(Point const a, Point const b, Point const c, float &area)
{ float	line[3];
	calcLineBetweenTwoPoints(a, b, line[A]);
	calcLineBetweenTwoPoints(c, b, line[B]);
	calcLineBetweenTwoPoints(a, c, line[C]);
	calcAreaOfTriangle(line, area);
	/*
	std::cout << "line a: "
		<< line[A]
		<< std::endl
		<< "line b: "
		<< line[B]
		<< std::endl
		<< "line c: "
		<< line[C]
		<< std::endl;
	*/
}
static void	calcLineBetweenTwoPoints(Point const one, Point const two, float &line)
{
	float	calculateX;
	float	calculateY;


	calculateX = std::pow(one.getX().toFloat() - two.getX().toFloat(), 2);
	calculateY = std::pow(one.getY().toFloat() - two.getY().toFloat(), 2);
	line = calculateX + calculateY;
	line = std::sqrt(line);
}

static void calcAreaOfTriangle(float line[3], float &area)
{
	float	s; //semiperimeter

	s = (line[A] + line[B] + line[C]) / 2;
	area = s * (s - line[A]) * (s - line[B]) * (s - line[C]);
	area = std::sqrt(area);
}
