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
    std::stack<int> stack_;

    bool input_check(const std::string &input) const;
    bool just_numbers_and_operands(const std::string &input) const;

};

#endif
