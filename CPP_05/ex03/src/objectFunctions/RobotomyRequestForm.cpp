/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:31:01 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/03 18:52:10 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <cstdlib>

//////////////////////////CONSTRUCTORS AND DESTRUCTORS/////////////////////////

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Roboto my Request Form", 72, 45, "The German government") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Roboto my Request Form", 72, 45, target) {}

RobotomyRequestForm
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  AForm::operator=(other);
  return (*this);
}


////////////////////////////////MEMBER FUNCTIONS///////////////////////////////

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  int random_number;
  std::string message;

  form_execution_check(executor);
  message = "Beep boop... Beep boop... Beep boop...";
  print_message_with_level(message, NOTE);
  random_number = rand();
  if (random_number % 2 == 1){
    message = target_ + " has been robotomized successfull";
    print_message_with_level(message, NOTE);
  }
  else {
    message = target_ + " robotomy failed";
    print_message_with_level(message, NOTE);
  }
}
