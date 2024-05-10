#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "header.hpp"

class  ShrubberyCreationForm : public AForm
{
  public:
    //Constructors
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm &operator = (const ShrubberyCreationForm &other);

    //Member functions
    void create_trees();
    void execute(Bureaucrat const & executor) const;

  private:
    ShrubberyCreationForm();
    std::string trees_[2];

};
#endif 
