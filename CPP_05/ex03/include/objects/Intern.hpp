#ifndef INTERN
#define INTERN

#include "header.hpp"

class Intern
{
  public:
    //Constructors and Destructors
    Intern();
    Intern(const Intern &);
    Intern &operator = (const Intern &);
    ~Intern();

    //Memberfunctions
    AForm *makeForm(const std::string &, const std::string &) const;

    //EXEPTIONS
    class Input_form_could_be_found : public std::exception {
      public:
        virtual const char *what() const throw();
    };
  private:

    //Privte memberfunctinos
    void   get_string_type(const std::string &string, int &type) const;

    typedef AForm* (*pfn_return_form)(const std::string &);
    static AForm *presidential_pardon_form_create(const std::string &target);
    static AForm *robotomy_request_form_create(const std::string &target);
    static AForm *shrubbery_creation_form_create(const std::string &target);

    //Pointer to memberfunction
    static const char *form_types_[NUMBER_OF_FORMS];
    static const pfn_return_form return_form_[NUMBER_OF_FORMS];
};

#endif
