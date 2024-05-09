#ifndef PRESIDENTIAL_PARADON_FORM
#define PRESIDENTIAL_PARADON_FORM

#include "header.hpp"

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm( void);
    PresidentialPardonForm( const PresidentialPardonForm &other );
    PresidentialPardonForm &operator = ( const PresidentialPardonForm &other );
    
  private:
};

#endif
