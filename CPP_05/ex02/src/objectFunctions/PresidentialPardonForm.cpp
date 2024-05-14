/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:30:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/14 08:33:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

//////////////////////////CONSTRUCTORS AND DESTRUCTORS/////////////////////////

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PRESIDENTAL PARADON FORM", 25, 5, "A Turkey") {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PRESIDENTAL PARADON FORM", 25, 5, target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  AForm::operator=(other);
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}


////////////////////////////////MEMBER FUNCTIONS///////////////////////////////

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  form_execution_check(executor);
  std::string message;
  message =
      "Message From the President: " + target_ + " get's pardoned by " + name_;
  print_message_with_level(message, NOTE);
}
