#ifndef PRESIDENTIAL_PARADON_FORM
#define PRESIDENTIAL_PARADON_FORM

#include "header.hpp"

class PresidentialPardonForm : public AForm
{
  public:
    //Constructor and Destructor
    PresidentialPardonForm( const PresidentialPardonForm &other );
    PresidentialPardonForm( const std::string &target );
    PresidentialPardonForm &operator = ( const PresidentialPardonForm &other );
    ~PresidentialPardonForm();

    //Memberfunctions
    void execute(Bureaucrat const & executor) const;
  private:
    PresidentialPardonForm();
};

#endif
