/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:10:07 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/11 09:45:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat(void) : name_("DEFAULT NAME"), grade_(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade)
    : name_(name), grade_(grade) {
  if (grade > 150)
    throw GradeTooHighException();
  if (grade < 1)
    throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this == &other)
    return (*this);
  grade_ = other.grade_;
  return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const std::string &Bureaucrat::get_name() const { return (name_); }

unsigned int Bureaucrat::get_grade() const { return (grade_); }

void Bureaucrat::promote_bureaucrat() {
  if (grade_ == 1)
    throw GradeTooHighException();
  grade_--;
}

void Bureaucrat::demotion_bureaucrat() {
  if (grade_ == 150)
    throw GradeTooLowException();
  grade_++;
}

void Bureaucrat::sign_form(AForm &form) {
  std::string message;

  try {
    form.be_signed(*this);
    message = name_ + " signed " + form.get_name();
    print_message_with_level(message, NOTE);
  }
  catch (std::exception &exception) {
    message = name_ + " couldn’t sign " + form.get_name() +
              " because: " + exception.what();
    print_message_with_level(message, NOTE);
  }
}

void Bureaucrat::executeForm(const AForm &form)
{
  std::string message;
  try
  {
    form.execute(*this);
    message = name_ + " executed " + form.get_name();
    print_message_with_level(message, NOTE);
  }
  catch (std::exception &exception) {
    message = name_ + " couldn’t executed " + form.get_name() +
              " because: " + exception.what();
    print_message_with_level(message, EXCEPTION);
  }

}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////EXEPTIONS///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade to High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade to Low");
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////OSTREAM OVERWRITE///////////////////////////
///////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat) {
  return ostream << "Bueraucrat named: " << bureaucrat.get_name()
                 << " currents grade is " << bureaucrat.get_grade() << "\n";
}
