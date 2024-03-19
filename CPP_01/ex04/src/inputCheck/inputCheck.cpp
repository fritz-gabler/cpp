/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:34:58 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/19 16:31:58 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void openFilesCheck(Input &input);
static void	convertInputToStdString(Input &input);
static void	isInputIsValidString(Input &input);

void	inptCheck(Input &input)
{
	if (input.ac != 4)
		return (errorOccured(WrongNumberOfArgs, input));
	convertInputToStdString(input);
	isInputIsValidString(input);
	openFilesCheck(input);
}

static void	convertInputToStdString(Input &input)
{
	if (input.process->status == Error)
		return ;
	input.fileName = input.av[1];
	input.stringOne = input.av[2];
	input.stringTwo = input.av[3];
}

static void	isInputIsValidString(Input &input)
{
	if (input.fileName.length() <= 0
		|| input.stringTwo.length() <= 0
		|| input.stringTwo.length() <= 0)
		input.process->status = false;
}

static void openFilesCheck(Input &input)
{
	std::ifstream	tmpFile;

	tmpFile.open(input.fileName.c_str());
	if (tmpFile.fail() == true)
		return (errorOccured(FileCantBeOpen, input));
	tmpFile.close();
}
