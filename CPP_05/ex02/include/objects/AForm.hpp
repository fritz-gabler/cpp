#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
public:
  // CONSTRUCTOR & DESTRUCTOR
  AForm();
  AForm(const AForm &other);
  AForm(const std::string name, const unsigned int required_grade_to_sign,
       const unsigned int grade_required_to_execute_, std::string target);
  AForm &operator=(const AForm &form);
  virtual ~AForm();

  // MEMBER FUNCTIONS
  void be_signed(const Bureaucrat &bueraucrat);
  unsigned int get_required_grade_to_sign() const;
  unsigned int get_required_grade_to_execute() const;
  const std::string &get_name() const;
  bool is_form_signed() const;
  void form_execution_check(Bureaucrat &bureaucrat) const;
  virtual void execute(const Bureaucrat &executor) const = 0;

  // CLASSES
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class Form_is_not_signed_exeption : public std::exception {
  public:
    virtual const char *what() const throw();
  };


protected:
  const std::string name_;
  bool is_signed_;
  const unsigned int required_grade_to_sign_;
  const unsigned int grade_required_to_execute_;
  std::string target_;
};

std::ostream &operator<<(std::ostream &ostream, const AForm &form);
#endif
