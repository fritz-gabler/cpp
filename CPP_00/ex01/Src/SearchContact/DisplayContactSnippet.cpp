/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayContactSnippet.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:36:31 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:44:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	DisplayFeeldStr(std::string Content)
{
	if (Content.length() < 11)
	{
		std::cout << std::right << std::setw(10) << Content;
		std::cout << "|";
	}
	else
	{
		std::cout << std::right << std::setw(9) << Content.substr(0, 9);
		std::cout << ".|";
	}
}

void	DisplayFeeldInt(int Content)
{
	std::cout << std::right << std::setw(10) << Content;
	std::cout << "|";
}

