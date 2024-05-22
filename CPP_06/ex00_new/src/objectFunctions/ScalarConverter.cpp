/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/22 11:05:10 by fgabler          ###   ########.fr       */
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
  converter.convert_all_types(input);
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

  if (is_special_number_sigh(input) == true)
    return (true);
  else if (mixed_input(input) == true)
  {
    log(MIXED_INPUT, ERROR);
    return (false);
  }
  else if (wrong_signs(input) == true)
  {
    log(WRONG_SIGNS, ERROR);
    return (false);
  }

  return (true);
}

bool ScalarConverter::is_special_number_sigh(const std::string &input) const
{
  if (input == "-inf" || input == "+inf" || input == "nan")
    return (true);
  return (false);
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
  if (std::isalpha(input[0]) != false && input.length() == 1)
      return (true);
  return (false);
}

void ScalarConverter::convert_all_types(const std::string &input)
{
  char_convert(input);
  /*
  if (error_message[CHAR] == "")
    std::cout << "char: " << char_converted_ << std::endl;
  else
    std::cout << "char: " << error_message[CHAR] << std::endl;
    */
}

void ScalarConverter::char_convert(const std::string &input)
{
  if (type_ == CHAR)
    char_converted_ = input[0];
  else if (type_ == INT && is_printable(input) == true)
    char_converted_ = static_cast<char>(std::atoi(input.c_str()));
  else if (is_printable(input) == false && is_ascii(input) == true)
    error_message[CHAR] = "Non displayable";
  else
    error_message[CHAR] = "impossible";
}

bool ScalarConverter::is_printable(const std::string &input) const
{
  if (is_in_int_range(input) == false)
    return (false);
  int number;

  number = static_cast<int>(std::atoi(input.c_str()));
  if (number < MIN_PRINTABLE || number > MAX_PRINTABLE)
    return (false);
  return (true);
}

bool ScalarConverter::is_in_int_range(const std::string &input) const
{
  if (input.length() > 11)
    return (false);
  long int number;
  number = static_cast<long int>(std::atol(input.c_str()));
  if (number < INT_MIN || number > INT_MAX )
    return (false);
  return (true);
}

bool ScalarConverter::is_ascii(const std::string &input) const
{
  if (is_in_int_range(input) == false)
    return (false);
  int number;

  number = static_cast<int>(std::atoi(input.c_str()));
  if (number < 0 || number > 127)
    return (false);
  return (true);
}
