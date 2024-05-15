/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_create_form_test.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:47:54 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/15 07:36:01 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"


void intern_create_form_works()
{
  AForm *test_form;
  Intern fred;
  Bureaucrat thomas("Thomas", 26);
  std::string message;

  std::cout << std::endl;
  message = "---------Intern Tyies to create Form: Success---------\n";
  print_message_with_level(message, TEST);
  try
  {
    test_form = fred.makeForm("presidential paradon", "Mr. Jakson");
    message = "YES intern good job, you created a form";
    print_message_with_level(message, NOTE);
  }
  catch (std::exception &exception)
  {
    message = "Oh no! That does not work!: " + std::string(exception.what());
    print_message_with_level(message, NOTE);
    return ;
  }
  thomas.sign_form(*test_form);
  thomas.executeForm(*test_form);
  delete test_form;
}

void intern_create_form_fails()
{

  AForm *test_form;
  Intern fred;
  Bureaucrat thomas("Thomas", 5);
  std::string message;

  std::cout << std::endl;
  message = "---------Intern Tyies to create Form: Fail---------\n";
  print_message_with_level(message, TEST);
  try
  {
    test_form = fred.makeForm("Wrong Form", "Mr. Jakson");
    message = "YES intern good job, you created a form";
    print_message_with_level(message, NOTE);
  }
  catch (std::exception &exception)
  {
    message = "Oh no! That does not work!: " + std::string(exception.what());
    print_message_with_level(message, NOTE);
  }
  (void) test_form;
}
