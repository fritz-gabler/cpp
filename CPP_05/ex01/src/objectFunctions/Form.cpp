/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:11:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/14 07:20:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/////////////////////////// CONSTRUCTOR AND DESTRUCTOR ////////////////////////

Form::Form()
    : name_("DEFAULT NAME"), is_signed_(false), required_grade_to_sign_(75),
      grade_required_to_execute_(60) {}

Form::Form(const Form &other)
    : name_(other.name_), is_signed_(other.is_signed_),
      required_grade_to_sign_(other.required_grade_to_sign_),
      grade_required_to_execute_(other.grade_required_to_execute_) {}

Form::Form(const std::string name, const unsigned int required_grade_to_sign,
           const unsigned int grade_required_to_execute)
    : name_(name), is_signed_(false),
      required_grade_to_sign_(required_grade_to_sign),
      grade_required_to_execute_(grade_required_to_execute) {
  if (required_grade_to_sign_ < 1 || grade_required_to_execute_ < 1)
    throw GradeTooHighException();
  if (required_grade_to_sign_ > 150 || grade_required_to_execute_ > 150)
    throw GradeTooLowException();
}

Form &Form::operator=(const Form &other) {
  if (this == &other)
    return (*this);
  is_signed_ = other.is_signed_;
  return (*this);
}

Form::~Form() {}

/////////////////////////////// MEMBER FUNCTIONS //////////////////////////////

void Form::be_signed(const Bureaucrat &bueraucrat) {
  if (is_signed_ == true)
    return ;
  if (bueraucrat.get_grade() > required_grade_to_sign_)
    throw GradeTooLowException();
  is_signed_ = true;
}

unsigned int Form::get_required_grade_to_sign() const {
  return (required_grade_to_sign_);
}

unsigned int Form::get_required_grade_to_execute() const {
  return (grade_required_to_execute_);
}

const std::string &Form::get_name() const { return (name_); }

bool Form::is_form_signed() const { return (is_signed_); }

///////////////////////////////// EXEPTIONS////////////////////////////////////

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade to HIGH");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade to LOW");
}

///////////////////////////////// EXEPTIONS////////////////////////////////////

std::ostream &operator<<(std::ostream &ostream, const Form &form) {
  std::string is_signed_status;

  if (form.is_form_signed() == true)
    is_signed_status = "true\n";
  else
    is_signed_status = "false\n";

  return ostream << "FORM NAME:           " << form.get_name()
                 << "\nSign grade:          "
                 << form.get_required_grade_to_sign()
                 << "\nGrade to execute:    "
                 << form.get_required_grade_to_execute()
                 << "\nIs form form signed: " << is_signed_status;
}
