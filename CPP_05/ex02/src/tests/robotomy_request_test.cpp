/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robotomy_request_test.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:58:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/10 17:05:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void robotomy_request_test()
{
  Bureaucrat thomas("Thomas", 7);
  Bureaucrat low_level_guy("Low level bureaucreat", 140);
  RobotomyRequestForm automate_it_please("robotomy");

  print_message_with_level("--------Robotomy request test--------", NOTE);
  automate_it_please.be_signed(thomas);

  thomas.executeForm(automate_it_please);
  low_level_guy.executeForm(automate_it_please);
}
