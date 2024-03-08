/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:13:13 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/08 18:12:03 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

static void	arg_check(int ac, int *error);
static void	capitalice_string(char **av, int error);
static void	capitalice_line(char *line);
static void	print_input(char **av, int error);

int	main(int ac, char **av)
{
	int	error = false;

	arg_check(ac, &error);
	capitalice_string(av, error);
	print_input(av, error);
	return (0);
}

static void	arg_check(int ac, int *error)
{
	std::string		no_argument = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac > 1)
		return ;
	*error = true;
	std::cout << no_argument << std::endl;
}

static void	capitalice_string(char **av, int error)
{
	int	i;

	if (error == true)
		return ;
	i = 1;
	while (av[i] != NULL)
	{
		capitalice_line(av[i]);
		i++;
	}
}

static void	capitalice_line(char *line)
{
	for(int i = 0; line[i] != '\0'; i++)
	{
		line[i] = std::toupper(line[i]);
	}
}

static void	print_input(char **av, int error)
{
	int	i;

	i = 1;
	if (error == true)
		return ;

	while (av[i] != NULL)
	{
		std::cout << av[i];
		i++;
	}
	std::cout << std::endl;
}
