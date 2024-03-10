/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:17:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:44:33 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

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
