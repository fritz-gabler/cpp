/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:29:05 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/12 18:49:26 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Intern::Intern() {
  form_types_ = {
    "PRESIDENTIAL PARADON",
    "ROBOTOMY REQUEST",
    "SHRUBBERY CREATION"
  };
}

Intern::Intern(const Intern &intern) {
  form_types_ = {
    "PRESIDENTIAL PARADON",
    "ROBOTOMY REQUEST",
    "SHRUBBERY CREATION"
  }
}

Intern &Intern::operator=(const Intern &intern) { return (*this); }

Intern::~Intern() {}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

AForm &Intern::makeForm(std::string &form_name,
                        const std::string &tardet_form) {
  int type;
  AForm *form;

  capitalize_string(form_name);
  get_string_type(form_name, type);
  switch(type)
  {
    case PRESIDENTIAL_FORM:
      form = PresidentialPardonForm(tardet_form);
      break;
    case ROBOTO_FORM:
      form = RobotomyRequestForm(tardet_form);
      break;
    case SHRUBBERY_FORM:
      form = ShrubberyCreationForm(tardet_form);
      break;
  }
  return (*form);
}

void Intern::get_string_type(std::string &string, int &type) {
  for (int i = 0; i < NUMBER_OF_FORMS; i++) {
    if (string.compare(form_types_[i]) = SAME_STRING) {
      type = i;
      return ;
    }
  }
  throw Input_form_could_be_found();
  type = -1;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////EXEPTIONS///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



