/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:31:29 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/09 19:15:29 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("DEFAULT NAME", 145, 137, "DEFAULT TARGET"), trees_(NULL) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("DEFAULT NAME", 145, 137, target), trees_(NULL) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
  ShrubberyCreationForm::operator=(other);
  return (*this);
}

void ShrubberyCreationForm::create_trees()
{
}
