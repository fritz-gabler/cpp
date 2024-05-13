#ifndef INTERN
#define INTERN

#include "header.hpp"

class Intern
{
  public:
    //Constructors and Destructors
    Intern();
    Intern(const Intern &intern);
    Intern operator = (const Intern &intern);
    ~Intern();

    //Memberfunctions
    AForm &makeForm(std::string &form_name, const std::string &target_form);
    void get_string_type(std::string &string, int &type);

    //EXEPTIONS
    class Input_form_could_be_found : public std::exception {
      public:
        virtual const char *what() const throw();
    };
  private:
    AForm *presidential_pardon_form_create(const std::string &target);
    AForm *robotomy_request_form_create(const std::string &target);
    AForm *shrubbery_creation_form_create(const std::string &target);

    static const char form_types_[NUMBER_OF_FORMS];
    static const AForm return_form_[NUMBER_OF_FORMS];
};

#endif
