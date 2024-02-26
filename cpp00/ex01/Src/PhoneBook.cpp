/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:17:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 11:49:59 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	Process		Process;
	PhoneBook	PhoneBook;

	HeaderPrint();
	SetProcess(&Process);
	while(Process.Status != Exit)
	{
		GetCommand(&Process);
		SetAction(&PhoneBook, &Process);
		PhoneBook.print();
	//	ResetPromt(&Process);
		ResetProcess(&Process);
	}
	return (0);
}
