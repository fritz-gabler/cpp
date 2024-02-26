/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetProcess.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:38:21 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/24 18:43:48 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	SetProcess(Process *Process)
{
	Process->Status = Start;
	Process->PrintedLines = 0;
}
