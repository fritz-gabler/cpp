/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupStruct.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:21:43 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/19 12:35:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void	setupInputStruct(Input &input, int ac, char **av);
static void	setupProcessStruct(Input &input);

void	setupStruct(Input &input, int ac, char **av)
{
	setupInputStruct(input, ac, av);
	setupProcessStruct(input);
}

static void	setupInputStruct(Input &input, int ac, char **av)
{

	input.av = av;
	input.ac = ac;
}

static void	setupProcessStruct(Input &input)
{
	static Process process;

	input.process = &process;
	input.process->status = RunLoop;
}
