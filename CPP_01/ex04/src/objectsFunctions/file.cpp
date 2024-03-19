/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:27:01 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/19 17:54:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

File::File(void)
{
	_outFile = 0;
	_infile = 0;
	_fileLine = NULL;
}
void	File::openFile(Input &input)
{
	std::string	replaceName;

	if (input.process->status == Error)
		return ;
	replaceName = ".replace"
	_outFile.open(input.fileName + replaceName);
	if (_outFile.fail() == true)
		errorOccured(FileCantBeOpen, input);
	_inFile.open(input.fileName);
	if (_inFile.fail() == true)
		errorOccured(FileCantBeOpen, input);
}

void	File::readLineFromFile(Input &input)
{
	if (input.process->status == Error)
		return ;
	_infile >> _fileLine << std::endl;
	if (_infile.eof() == true)
		input.process
}

void	File::searchAndReplaceString(Input &input)
{
	int	i;
	int	strLenght;

	if (input.process->status == Error)
		return ;
	i = 0;
	strLenght = input.stringOne.lenght;
	while (_fileLine[i] != '\0')
	{
		if (std::strncmp(_fileLine[i], inpu.stringOne, strLenght)
		i++;
	}
}
