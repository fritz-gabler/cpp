/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_prompt.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:17:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/29 16:50:18 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	reset_prompt(Process *Process)
{
	int	i;

	i = 0;
	while (Process->PrintedLines != i)
	{
		std::cout << UP << CUT;
		i++;
	}
}
