#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
public:
  // CONSTRUCTOR & DESTRUCTOR
  Form();
  Form(const Form &other);
  Form(const std::string name, const unsigned int required_grade);
  Form &operator=(const Form &form);
  ~Form();

  // MEMBER FUNCTIONS
  void be_signed(const Bureaucrat &bueraucrat);
  unsigned int get_required_grade() const;
  const std::string get_name() const;

  // CLASSES
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
  bool is_signed_;
  const unsigned int required_grade_;
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);
#endif
