/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:31:29 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/10 11:30:23 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

//////////////////////////CONSTRUCTORS AND DESTRUCTORS/////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("DEFAULT NAME", 145, 137, "DEFAULT TARGET") {
  create_trees();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("DEFAULT NAME", 145, 137, target) {
  create_trees();
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  AForm::operator=(other);
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

////////////////////////////////////EXEPTIONS//////////////////////////////////

const char *ShrubberyCreationForm::File_failed_to_open::what() const throw() {
  return ("File failed to open");
}

////////////////////////////////MEMBER FUNCTIONS///////////////////////////////

void ShrubberyCreationForm::create_trees() {
  trees_[0] = "          $$\n\
            $$\n\
           $$$$\n\
          $$$$$$$\n\
         $$$$$$$$$\n\
        $$$$$$$$$$$\n\
       $$$$$$$$$$$$$\n\
      $$$$$$$$$$$$$$$\n\
     $$$$$$$$$$$$$$$$$\n\
    $$$$$$$$$$$$$$$$$$$\n\
   $$$$$$$$$$$$$$$$$$$$$\n\
  $$$$$$$$$$$$$$$$$$$$$$$\n\
           $$$$$\n\
           $$$$$\n\
           $$$$$\n\
    ";

  trees_[1] = "       @@@\n\
         @@@\n\
        @@@@@\n\
        @@@@@\n\
       @@@@@@@\n\
      @@@@@@@@@\n\
     @@@@@@@@@@@\n\
    @@@@@@@@@@@@@\n\
   @@@@@@@@@@@@@@@\n\
  @@@@@@@@@@@@@@@@@\n\
         @@@\n\
         @@@\n\
         @@@\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  form_execution_check(executor);

  std::string message;
  std::ofstream outfile(std::string(target_ + "_shrubbery").c_str());

  if (outfile.fail() == true)
    throw File_failed_to_open();
  outfile << trees_[0] << std::endl;
  outfile << trees_[1] << std::endl;
  message = "Trees are now in file: " + target_ + "_shrubbery";
  print_message_with_level(message, NOTE);
  outfile.close();
}
