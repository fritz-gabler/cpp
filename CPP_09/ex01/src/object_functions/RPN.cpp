/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:38:33 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/03 17:13:49 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

/////////////////////////////////CONSTRUCTOR///////////////////////////////////

RPN::RPN() {}

RPN::RPN(const RPN &other) : stack_(other.stack_) {}

RPN &RPN::operator = (const RPN &other)
{
  if (this = &other)
    *this = other;
  return (*this);
}

RPN::~RPN() {}

///////////////////////////////////MEMBER FUNCTIONS////////////////////////////

void RPN::calculate(const std::string &input)
{
}

void RPN::input_check(std::string &input) const
{
}

bool just_numbers_and_operands(const std::string &input) const
{
  for(int i = 0; input[i] != '\0'; i++)
  {
    if (input[i] == '*'
        || input[i] == '+'
        || input[i] == '-'
        || input[i] == '/'
        || input[i] == ' ')
      i++;
    if (isdigit(input[i]) == false)
      return (false);
  }
  return (true);
}

