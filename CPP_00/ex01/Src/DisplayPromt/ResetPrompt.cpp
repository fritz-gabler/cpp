/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResetPromt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:17:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:42:05 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	ResetPromt(Process *Process)
{
	int	i;

	i = 0;
	while (Process->PrintedLines != i)
	{
		std::cout << UP << CUT;
		i++;
	}
}
