/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetProcess.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:38:21 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:44:07 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	SetProcess(Process *Process)
{
	Process->Status = Start;
	Process->PrintedLines = 0;
}
