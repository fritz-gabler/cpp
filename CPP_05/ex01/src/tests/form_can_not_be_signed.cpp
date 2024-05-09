/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_can_not_be_signed.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:25:31 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/09 16:54:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void form_can_not_be_signed()
{
  Form b_twenty_one("Bos Form", 20, 15);
  Bureaucrat low_level_guy("LOW level bureaucrat", 150);
  std::string message;
  
  std::cout << "\n-----------CAN NOT BE SIGNED TEST-----------\n\n";
  print_message_with_level("Form status before trying to sign it:", NOTE);
  std::cout << b_twenty_one;
  std::cout << "\n";
  try {
    b_twenty_one.be_signed(low_level_guy);
  }
  catch (Form::GradeTooLowException &) {
    message = "Caught exception GRADE TO LOW to sign from: " +
      low_level_guy.get_name() + "\n";
    print_message_with_level(message, WARNING);
  }
  catch (Form::GradeTooHighException &exception)
  {
    message = "Caught  exception GRADE TO HIGH to sign from: " +
      b_twenty_one.get_name() + " " + exception.what();
    print_message_with_level(message, WARNING);
  }
  print_message_with_level("Form status after trying to sign it:", NOTE);
  std::cout << "\n";
  std::cout << b_twenty_one;
}
