/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrubbery_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:37:51 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/11 09:49:29 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void shrubbery_test() {
  Bureaucrat thomas("Thomas", 6);
  Bureaucrat low_level_guy("Mark", 140);
  ShrubberyCreationForm creat_a_tree_for_me("tree");
  std::string message;

  std::cout << "\n";
  print_message_with_level("------SHRUBBERY CREATE A TREE------\n", TEST);

  creat_a_tree_for_me.be_signed(thomas);
  thomas.executeForm(creat_a_tree_for_me);
  low_level_guy.executeForm(creat_a_tree_for_me);
}
