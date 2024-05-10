/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:11:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/10 11:01:05 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/////////////////////////// CONSTRUCTOR AND DESTRUCTOR ////////////////////////

AForm::AForm()
    : name_("DEFAULT NAME"), is_signed_(false), required_grade_to_sign_(75),
      grade_required_to_execute_(60), target_("DEFAULT TYPE") {}

AForm::AForm(const AForm &other)
    : name_(other.name_), is_signed_(other.is_signed_),
      required_grade_to_sign_(other.required_grade_to_sign_),
      grade_required_to_execute_(other.grade_required_to_execute_),
      target_(other.target_) {}

AForm::AForm(const std::string name, const unsigned int required_grade_to_sign,
             const unsigned int grade_required_to_execute, std::string target)
    : name_(name), is_signed_(false),
      required_grade_to_sign_(required_grade_to_sign),
      grade_required_to_execute_(grade_required_to_execute), target_(target) {
  if (required_grade_to_sign_ < 1 || grade_required_to_execute_ < 1)
    throw GradeTooHighException();
  if (required_grade_to_sign_ > 150 || grade_required_to_execute_ > 150)
    throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other) {
  if (this == &other)
    return (*this);
  is_signed_ = other.is_signed_;
  return (*this);
}

AForm::~AForm() {}

/////////////////////////////// MEMBER FUNCTIONS //////////////////////////////

void AForm::be_signed(const Bureaucrat &bueraucrat) {
  if (is_signed_ == true)
    return;
  if (required_grade_to_sign_ <= bueraucrat.get_grade())
    throw GradeTooLowException();
  is_signed_ = true;
}

unsigned int AForm::get_required_grade_to_sign() const {
  return (required_grade_to_sign_);
}

unsigned int AForm::get_required_grade_to_execute() const {
  return (grade_required_to_execute_);
}

const std::string &AForm::get_name() const { return (name_); }

bool AForm::is_form_signed() const { return (is_signed_); }

void AForm::form_execution_check(const Bureaucrat &bureaucrat) const {
  if (is_signed_ == false)
    throw Form_is_not_signed_exeption();
  if (bureaucrat.get_grade() > grade_required_to_execute_)
    throw GradeTooHighException();
}

///////////////////////////////// EXEPTIONS////////////////////////////////////

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade to HIGH");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade to LOW");
}

const char *AForm::Form_is_not_signed_exeption::what() const throw() {
  return ("Form is not signed");
}

///////////////////////////////// EXEPTIONS////////////////////////////////////

std::ostream &operator<<(std::ostream &ostream, const AForm &form) {
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
