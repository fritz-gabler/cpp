/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:29:05 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/14 06:41:41 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <string>

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern &Intern::operator=(const Intern &) { return (*this); }

Intern::~Intern() {}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////SET STATIC TYPES///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const char *Intern::form_types_[NUMBER_OF_FORMS] = {
    "PRESIDENTIAL PARADON",
    "ROBOTOMY REQUEST",
    "SHRUBBERY CREATION"
};

const Intern::pfn_return_form Intern::return_form_[] = {
    &Intern::presidential_pardon_form_create,
    &Intern::robotomy_request_form_create,
    &Intern::shrubbery_creation_form_create
};

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

AForm *Intern::makeForm(const std::string &form_name,
                        const std::string &tardet_form) const{
  int type;
  std::string capitalized_str;

  capitalize_string(form_name, capitalized_str);
  get_string_type(capitalized_str, type);
  return (return_form_[type](tardet_form));
}

void Intern::get_string_type(const std::string &string, int &type) const {
  for (int i = 0; i < NUMBER_OF_FORMS; i++)
  {
    if (string == form_types_[i])
    {
      type = i;
      return ;
    }
  }
  type = -1;
  throw Input_form_could_be_found();
}

AForm *Intern::presidential_pardon_form_create(const std::string &target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::robotomy_request_form_create(const std::string &target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::shrubbery_creation_form_create(const std::string &target) {
    return (new ShrubberyCreationForm(target));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////EXEPTIONS///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const char *Intern::Input_form_could_be_found::what() const throw() {
  return ("Input coudln't be found");
}
