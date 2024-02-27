/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:17:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 18:38:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	Process		process;
	PhoneBook	phoneBook;

	HeaderPrint();
	SetProcess(&process);
	while(process.Status != Exit)
	{
		GetCommand(&process);
		SetAction(&phoneBook, &process);
		ResetPromt(&process);
		ResetProcess(&process);
	}
	return (0);
}
