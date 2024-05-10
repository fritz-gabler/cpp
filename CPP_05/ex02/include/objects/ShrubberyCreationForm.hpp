#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "header.hpp"

class  ShrubberyCreationForm : public AForm
{
  public:
    //Constructors
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm &operator = (const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    //Member functions
    void create_trees();
    void execute(Bureaucrat const & executor) const;

    //Exeptions
    class File_failed_to_open : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  private:
    ShrubberyCreationForm();
    std::string trees_[2];

};
#endif 
