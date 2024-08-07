#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
  public:
    RPN();
    RPN(const RPN &other);
    RPN &operator = (const RPN &other);
    ~RPN();

    void calculate(const std::string &input);

  private:
    std::stack<double> stack_;

    bool input_check(const std::string &input) const;
    bool just_numbers_and_operands(const std::string &input) const;
    bool no_greater_numbers_than_nine(const std::string &input) const;
    void remove_operators(std::string &input) const;
    bool right_amount_of_operands(const std::string &input) const;
    bool is_operator(char c) const;
    void multiply();
    void add();
    void subtract();
    void divide();
    
    class divisor_is_zero_exception: public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif
