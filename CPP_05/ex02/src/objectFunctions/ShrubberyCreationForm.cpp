/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:31:29 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/10 10:09:36 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

//////////////////////////CONSTRUCTORS AND DESTRUCTORS/////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("DEFAULT NAME", 145, 137, "DEFAULT TARGET"), trees_(NULL) {
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
  ShrubberyCreationForm::operator=(other);
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

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
  form_executions_check(executor);
  std::ofstream outfile;
  outfile = open(std::string(target_ + "_shrubbery").c_str);
  if (ostream.fail == true)
    return (print_message_with_level("File failed to open", ERROR), NULL);
  outfile << trees_[0] << std::endl;
  outfile << trees_[1] << std::endl;
  print_message_with_level("Trees are now in file: " + target_ + "_shrubbery",
                           INFO) outfile.close();
}
