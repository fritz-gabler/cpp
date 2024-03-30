/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceStringOneWithStringTow.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:04:00 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/30 20:21:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void	removeStringOne(Input &input, std::string &fileLine, int i);
static void	insertStringTwo(Input &input, std::string &fileLine, int i);

void	replaceStrOneWithStrTow(Input &input, std::string &fileLine, int i)
{
	removeStringOne(input, fileLine, i);
	insertStringTwo(input, fileLine, i);
}

static void	removeStringOne(Input &input, std::string &fileLine, int i)
{
	fileLine.erase(i, input.stringOne.length());
}

static void	insertStringTwo(Input &input, std::string &fileLine, int i)
{
	fileLine.insert(i, input.stringTwo);
}
