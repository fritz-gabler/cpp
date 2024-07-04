/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:38:33 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/04 09:17:31 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include "header.hpp"
#include <sstream>

/////////////////////////////////CONSTRUCTOR///////////////////////////////////

RPN::RPN() {}

RPN::RPN(const RPN &other) : stack_(other.stack_) {}

RPN &RPN::operator = (const RPN &other)
{
  if (this == &other)
    *this = other;
  return (*this);
}

RPN::~RPN() {}

///////////////////////////////////MEMBER FUNCTIONS////////////////////////////

void RPN::calculate(const std::string &input)
{
  if (input_check(input) == false)
    return (log(WRONG_INPUT, ERROR));

  for (int i = 0; input[i] != '\0'; i++)
  {
    if (isdigit(input[i]))
      stack_.push(input[i] - '0');
    else if (input[i] == '*' && stack_.size() >= 2)
      multiply();
    else if (input[i] == '+' && stack_.size() >= 2)
      add();
    else if (input[i] == '-'&& stack_.size() >= 2
              && divisor_is_null() == false)
      subtract();
    else if (input[i] == '/' && stack_.size() >= 2)
      divide();
    else if (input[i] == ' ')
      ;
    else
      return (log(WRONG_INPUT, ERROR));
  }

  if (stack_.size() == 1)
    std::cout << stack_.top() << std::endl;
  else
    (log(WRONG_INPUT, ERROR));
}

bool RPN::input_check(const std::string &input) const
{
  if (just_numbers_and_operands(input) == false)
    return (false);
  else if (no_greater_numbers_than_nine(input) == false)
    return (false);
  else if (is_operator(input[0]) == true)
    return (false);
  else if (right_amount_of_operands(input) == false)
    return (false);
  return (true);
}

bool RPN::just_numbers_and_operands(const std::string &input) const
{
  for(int i = 0; input[i] != '\0'; i++)
  {
    if (is_operator(input[i]) == true || input[i] == ' ')
      ;
    else if (isdigit(input[i]) == false)
      return (false);
  }
  return (true);
}

bool RPN::no_greater_numbers_than_nine(const std::string &input) const
{
  std::string cpy_input;
  std::istringstream convert;
  int number;

  cpy_input = input;
  remove_operators(cpy_input);

  for (convert.str(cpy_input); convert.eof() == false; convert >> number)
  {
    if (number > 9)
      return (false);
  }
  return (true);
}


void RPN::remove_operators(std::string &input) const
{
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (is_operator(input[i]) == true)
      input.erase(input.begin() + i);
  }
}

bool RPN::right_amount_of_operands(const std::string &input) const
{
  int operands_number = 0;
  int operators_number = 0;

  for (int i = 0; input[i] != '\0'; i++)
  {
    if (is_operator(input[i]) == true)
      operators_number++;
    else if (isdigit(input[i]))
      operands_number++;
  }

  if ((operators_number + 1) == operands_number)
    return (true);
  return (false);
}

bool RPN::is_operator(char c) const
{
  if (c == '*' || c == '+' || c == '-' || c == '/')
    return (true);
  return (false);
}

bool RPN::divisor_is_null()
{
  if (stack_.top() == 0)
    return (true);
  return (false);
}

void RPN::multiply()
{
  int factor[2];

  factor[0] = stack_.top();
  stack_.pop();
  factor[1] = stack_.top();
  stack_.pop();

  stack_.push(factor[0] * factor[1]);
}

void RPN::add()
{
  int addend[2];

  addend[0] = stack_.top();
  stack_.pop();
  addend[1] = stack_.top();
  stack_.pop();

  stack_.push(addend[0] + addend[1]);
}

void RPN::subtract()
{
  int subtrahend;
  int minuend;

  subtrahend = stack_.top();
  stack_.pop();
  minuend = stack_.top();
  stack_.pop();

  stack_.push(minuend - subtrahend);
}

void RPN::divide()
{
  int divisor;
  int dividend;

  divisor = stack_.top();
  stack_.pop();
  dividend = stack_.top();
  stack_.pop();

  stack_.push(dividend / divisor);
}
