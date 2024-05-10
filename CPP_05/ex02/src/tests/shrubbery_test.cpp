/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrubbery_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:37:51 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/10 12:08:12 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void shrubbery_test() {
  Bureaucrat thomas("Thomas", 6);
  Bureaucrat low_level_guy("Mark", 140);
  ShrubberyCreationForm creat_a_tree_for_me("tree");
  std::string message;

  print_message_with_level("\n------SHRUBBERY CREATE A TREE------\n", NOTE);
  try {
    thomas.executeForm(creat_a_tree_for_me);
    print_message_with_level("Yes it worked a tree got created", NOTE);
  }
  catch (std::exception &exception) {
    message =
        "NO creating a tree did not work! " + std::string(exception.what());
    print_message_with_level(message, NOTE);
  }

  try {
    low_level_guy.executeForm(creat_a_tree_for_me);
    print_message_with_level("Yes it worked a tree got created", NOTE);
  }
  catch (std::exception &exception) {
    message =
        "NO creating a tree did not work! " + std::string(exception.what());
    print_message_with_level(message, NOTE);
  }
}
