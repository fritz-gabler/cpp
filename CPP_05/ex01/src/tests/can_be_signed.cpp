/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_be_signed.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:38 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/09 16:48:31 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void can_be_signed_test()
{
  Form b_twenty_one("b-21", 71, 60);
  Bureaucrat bos("High level bureaucrat", 1);
  std::string message;

  std::cout << "-----------CAN BE SIGNED TEST-----------\n\n";
  print_message_with_level("Form status before signing it:", NOTE);
  std::cout << b_twenty_one << std::endl;
  try {
    b_twenty_one.be_signed(bos);
  }
  catch (Form::GradeTooLowException &exception) {
    message = "Caught exception GRADE TO LOW to sign from: " +
    b_twenty_one.get_name() + " " + exception.what();
    print_message_with_level(message, WARNING);
  }
  catch (Form::GradeTooHighException &exception)
  {
    message = "Caught exception GRADE TO HIGH to sign from: " +
    b_twenty_one.get_name() + " " + exception.what();
    print_message_with_level(message, WARNING);
  }
  catch (std::exception &exception)
  {
    message = "Caught exception GRADE TO HIGH to sign from: " +
    b_twenty_one.get_name() + " " + exception.what();
    print_message_with_level(message, WARNING);
  }
  std::cout << "\n";
  print_message_with_level("Form status after signing:", NOTE);
  std::cout << b_twenty_one;
}
