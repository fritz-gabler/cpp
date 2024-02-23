/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:17:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/23 09:33:19 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	Process		Process;
	PhoneBook	PhoneBook;

	HeaderPrint();
	Process.Status = Start;
	while(Process.Status != Exit)
	{
		Process.PrintedLines = 0;
		GetCommand(&Process);
		SetAction(&PhoneBook, &Process);
	}
	return (0);
}
