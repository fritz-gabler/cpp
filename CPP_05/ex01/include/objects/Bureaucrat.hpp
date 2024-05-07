#ifndef BUREAUCRAT
#define BUREAUCRAT

#include "header.hpp"
class Form;

class Bureaucrat {
public:
  // Constructor and Destructor
  Bureaucrat(void);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat(const std::string &name, unsigned int grade);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat(void);

  // Memberfunctions
  const std::string &get_name() const;
  unsigned int get_grade() const;
  void promote_bureaucrat();
  void demotion_bureaucrat();
  void sign_form(Form &form);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  const std::string name_;
  unsigned int grade_;
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif
