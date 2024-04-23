/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isInputString.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:27:06 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/23 15:42:09 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

bool	isInputString(std::string fileLine, Input &input)
{
	int	strLeng;

	strLeng = input.stringOne.length();
	if (strncmp((fileLine.c_str()), input.stringOne.c_str(), strLeng) == FoundStr)
		return (true);
	return (false);
}
