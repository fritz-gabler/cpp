/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:11:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/07 14:31:44 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/////////////////////////// CONSTRUCTOR AND DESTRUCTOR ////////////////////////

Form::Form() : name_("DEFAULT NAME"), is_signed_(false), required_grade_(75) {}

Form::Form(const Form &other)
    : name_(other.name_), is_signed_(other.is_signed_),
      required_grade_(other.required_grade_) {}

Form::Form(const std::string name, const unsigned int required_grade)
    : name_(name), required_grade_(required_grade) {
  if (required_grade_ < 1)
    throw GradeTooHighException();
  if (required_grade_ > 150)
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
  if (bueraucrat.get_grade() < 1)
    throw GradeTooHighException();
  if (bueraucrat.get_grade() > 150)
    throw GradeTooLowException();
  is_signed_ = true;
}

unsigned int Form::get_required_grade() const { return (required_grade_); }

const std::string Form::get_name() const { return (name_); }

///////////////////////////////// EXEPTIONS ///////////////////////////////////

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade to HIGH");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade to LOW");
}
