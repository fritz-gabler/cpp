/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/21 18:34:58 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "define.hpp"
#include "functions.hpp"
#include <cstdlib>
#include <cstring>
#include <limits.h>
#include <stdlib.h>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter() : 
  type_(NOT_DEFINED),
  char_converted_(0),
  int_converted_(0),
  float_converted_(0),
  double_converted_(0) {}


ScalarConverter::ScalarConverter(const ScalarConverter &other) :
  type_(other.type_),
  char_converted_(other.int_converted_),
  int_converted_(other.char_converted_),
  float_converted_(other.float_converted_),
  double_converted_(other.double_converted_) {}



ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if(this != &other)
    *this = other;
  return (*this);
}

ScalarConverter::~ScalarConverter() {}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ScalarConverter::convert(const std::string &input) {
  ScalarConverter converter;

  converter.set_type_due_to_first_char(input);
  if (converter.class_input_check(input) == false)
    return ;
}

void ScalarConverter::set_type_due_to_first_char(const std::string &input)
{
  if (std::isdigit(input[0]) != 0 || (input[0] == '-' || input[0] == '+'))
    type_ = INT;
  else if (std::isalpha(input[0]) != false)
    type_ = CHAR;
}

bool ScalarConverter::class_input_check(const std::string &input) const
{

  if (mixed_input(input) == true)
  {
    log(MIXED_INPUT, ERROR);
    return false;
  }
  else if (wrong_signs(input) == true)
  {
    log(WRONG_SIGNS, ERROR);
    return (false);
  }

  return (true);
}

bool ScalarConverter::mixed_input(const std::string &input) const
{
  if (is_char_in_str(input) == true && is_number_in_str(input) == true)
    return (true);
  return (false);
}

bool ScalarConverter::is_char_in_str(const std::string &input) const
{
  for(int i = 0; input[i] != '\0'; i++)
  {
    if (std::isalpha(input[i]) != false)
      return (true);
  }
  return (false);
}

bool ScalarConverter::is_number_in_str(const std::string &input) const
{
  for(int i = 0; input[i] != '\0'; i++)
  {
    if (std::isdigit(input[i]) != false)
      return (true);
  }
  return (false);
}

bool ScalarConverter::wrong_signs(const std::string &input) const
{
  if (type_ == CHAR && just_valid_chars(input) == false)
    return (true);
  if (type_ == INT && just_valid_numbers(input) == false)
    return (true);
  return (false);
}

bool ScalarConverter::just_valid_numbers(const std::string &input) const
{
  int i;
  int found_decimal;

  i = 0;
  found_decimal = 0;
  if (input[0] == '-' || input[0] == '+')
    i = 1;
  while (input[i] != '\0')
  {
    if (input[i] == '.' && found_decimal == 0)
    {
      found_decimal++;
      i++;
    }
    if (found_decimal > 1)
      return (false);
    if (std::isdigit(input[i]) == false)
      return (false);
    i++;
  }
  return (true);
}

bool ScalarConverter::just_valid_chars(const std::string &input) const
{
  for(int i = 0; input[i] != '\0'; i++)
  {
    if (std::isalpha(input[i]) == false)
      return (false);
  }
  return (true);
}
