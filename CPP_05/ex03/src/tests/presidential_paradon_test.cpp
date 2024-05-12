/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidential_paradon_test.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:50:24 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/11 13:27:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void presidential_paradon_test()
{
  Bureaucrat thomas("Thomas", 1);
  Bureaucrat low_level_bureaucrat("Low level bureaucrat", 140);
  PresidentialPardonForm presidential_form("A Turkey");

  std::cout << std::endl;
  print_message_with_level("---------Presidential Paradon---------\n", TEST);
  presidential_form.be_signed(thomas);
  print_message_with_level("Thomas (grade one) ties to execute the form\n", TEST);
  thomas.executeForm(presidential_form);
  std::cout << std::endl;
  print_message_with_level("Low (grade 140) tries to execute the form\n", TEST);
  low_level_bureaucrat.executeForm(presidential_form);
}
