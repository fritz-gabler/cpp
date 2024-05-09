#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "header.hpp"

class  ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm &operator = (const ShrubberyCreationForm &other);

    void create_trees();

  private:
    std::string trees_[5];

};
#endif 
