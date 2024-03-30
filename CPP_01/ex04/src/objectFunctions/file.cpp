/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:27:01 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/30 20:49:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <string>

File::File(void){}

void	File::openFile(Input &input)
{
	std::string	replaceName;

	if (input.process->status == Error)
		return ;
	replaceName = ".replace";
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
	std::getline(_inFile, _fileLine);
	if (_inFile.eof() == true)
		input.process->status = StopLoop;
}

void	File::searchAndReplaceString(Input &input)
{
	int	i;

	i = 0;
	if (input.process->status == Error || input.process->status == StopLoop)
		return ;
	while (_fileLine[i] != '\0')
	{
		if (isInputString((_fileLine.substr(i)), input) == true)
			replaceStrOneWithStrTow(input, _fileLine, i);
		i++;
	}
}

void	File::writeLineToNewFile(Input &input)
{
	if (input.process->status == Error || input.process->status == StopLoop)
		return ;
	_outFile << _fileLine << std::endl;
}
