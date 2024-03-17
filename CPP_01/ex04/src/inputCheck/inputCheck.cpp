/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:34:58 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/17 16:02:38 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <cctype>
#include <cinttypes>

static void	setupInputStruct(Input *input, int ac, char **av);
static void openFilesCheck(Input &input);
static void	convertInputToStdString(char **input, std::string &stdInput[4]);
static void	isInputIsValidString(std::string stdInput);

void	inptCheck(Input &input, int ac, char **av)
{
	setupProcessStruct(input);
	if (ac != 4)
		return (errorOccured(WrongNumberOfArgs, input));
	convertInputToStdString(av, stdInput);
	isInputIsValidString(stdInput);
	openFilesCheck(input);
	convertInputToStdString(av, stdInput);
}

static void	setupInputStruct(Input &input, int ac, char **av)
{
	static Process process;

	input.av = av;
	input.ac = ac;
	input->process = &process;
}

static void	convertInputToStdString(Input &input)
{
	if (input.process.status == Error)
		return ;
	input.fileName = input.av[1];
	input.stringOne = input.av[2];
	input.stringTwo = input.av[3];
}

static void	isInputIsValidString(Input &input)
{
	if (input.fileName.length <= 0
		|| input.fistName.length() <= 0
		|| input.stringTwo.length <= 0)
		input.process.status = false;
}


static void openFilesCheck(Input &input)
{
	std::ofstream	tmpFile;

	tmpFile.open (input.av[2]);
	if (tmpFile.is_open() == false)
		return (errorOccured(FileCantBeOpend, input));
	tmpFile.close();
	tmpFile.open (input.av[3]);
	if (tmpFile.is_open() == false)
		return (errorOccured(FileCantBeOpen, input));
	tmpFile.close();
}
