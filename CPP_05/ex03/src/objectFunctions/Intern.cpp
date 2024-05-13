/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:29:05 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/13 14:22:19 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Intern::Intern() {}

Intern::Intern(const Intern &intern) {}

Intern &Intern::operator=(const Intern &intern) { return (*this); }

Intern::~Intern() {}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////SET STATIC TYPES///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

static const Intern::form_types_[NUMBER_OF_FORMS] {
    "PRESIDENTIAL PARADON",
    "ROBOTOMY REQUEST",
    "SHRUBBERY CREATION"
};

static const AForm::return_form_[NUMBER_OF_FORMS] {
  &AForm::presidential_pardon_form_create,
  &AForm::robotomy_request_form_create,
  &AForm::shrubbery_creation_form_create
};

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

AForm &Intern::makeForm(std::string &form_name,
                        const std::string &tardet_form) {
  int type;
  AForm *form;

  capitalize_string(form_name);
  get_string_type(form_name, type);
  return (return_form_[type](tardet_form));
}

void Intern::get_string_type(std::string &string, int &type) {
  for (int i = 0; i < NUMBER_OF_FORMS; i++) {
    if (string.compare(form_types_[i]) = SAME_STRING) {
      type = i;
      return ;
    }
  type = -1;
  throw Input_form_could_be_found();
}

AForm *AForm::presidential_pardon_form_create(const std::string &target)
}
  return (new PresidentialPardonForm(target));
{

AForm *AForm::RobotomyRequestForm(const std::string &target)
{
  return (new RobotomyRequestForm);
}

AForm *AForm::RobotomyRequestForm(const std::string &target)
{
  return (new ShrubberyCreationForm(target));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////EXEPTIONS///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const char *Intern::Input_could_not_be_found() const throw() {
  return ("Input coudln't be found");
}
