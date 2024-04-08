/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:55:34 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/08 18:46:59 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main( void )
{
	Point	Apoint(4.5f, 2.5f);
	Point	Bpoint(7.5f, 8.5f);
	Point	Cpoint(1.5f, 0.5f);

	bsp(Apoint, Bpoint, Cpoint, Cpoint);
	return 0;
}

