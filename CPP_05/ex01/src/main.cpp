/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:35:10 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/07 15:03:06 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void can_be_signed_test();
static void form_can_not_be_signed();

int main() {
  can_be_signed_test();
  form_can_not_be_signed();
  return (false);
}

static void can_be_signed_test()
{
  Form b_twenty_one("b-21", 71);
  Bureaucrat bos("High level bureaucrat", 1);
  std::string message;

  try {
    b_twenty_one.be_signed(bos);
  }
  catch (Form::GradeTooLowException &exeption) {
    message = "Chatched exeption GRADE TO LOW to sign from: " +
      b_twenty_one.get_name() + " " + exeption.what() + "\n";
    print_message_with_level(message, WARNING);
  }
  catch (Form::GradeTooHighException &exeption)
  {
    message = "Chatched exeption GRADE TO HIGH to sign from: " +
      b_twenty_one.get_name() + " " + exeption.what() + "\n";
    print_message_with_level(message, WARNING);
  }
}

static void form_can_not_be_signed()
{
  Form b_twenty_one("b-21", 71);
  Bureaucrat bos("High level bureaucrat", 1);
  std::string message;

  try {
    b_twenty_one.be_signed(bos);
  }
  catch (Form::GradeTooLowException &exeption) {
    message = "Chatched exeption GRADE TO LOW to sign from: " +
      b_twenty_one.get_name() + " " + exeption.what() + "\n";
    print_message_with_level(message, WARNING);
  }
  catch (Form::GradeTooHighException &exeption)
  {
    message = "Chatched exeption GRADE TO HIGH to sign from: " +
      b_twenty_one.get_name() + " " + exeption.what() + "\n";
    print_message_with_level(message, WARNING);
  }
}
