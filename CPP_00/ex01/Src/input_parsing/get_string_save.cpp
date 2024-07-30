/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getStringSave.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:10:33 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/11 14:19:51 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	getStringSave(std::string &input, Process &process)
{
	if (process.Status == Exit)
		return ;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		process.Status = Exit;
		process.PrintedLines = 0;
	}
}
