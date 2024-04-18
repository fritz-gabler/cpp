/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inBrainCapacityRange.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:11 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/18 19:10:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

bool	inBrainCapacityRange(int number)
{
	if (number < 0 || number > (BRAIN_CAPACITY - 1))
	{
		std::cout << "Idea number: ["
			<< number 
			<< "] isn't in Bran capacity range: ["
			<< (BRAIN_CAPACITY - 1)
			<< "]. Please input a value inside the range."
			<< std::endl;
		return (false);
	}
	return (true);
}
