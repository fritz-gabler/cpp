/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorOccured.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:00:09 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/17 16:14:57 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <iostream>

void	errorOccured(char *errorMessage, Input &input)
{
	input->process->status = Error;
	std::cout
		<< errorMessage
		<< std::endl;
}
