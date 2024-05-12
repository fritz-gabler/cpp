#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include "header.hpp"

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm operator=(const RobotomyRequestForm &other);

    //Memberfunctions
    void execute(Bureaucrat const & executor) const;
  private:
    RobotomyRequestForm();
};
#endif
