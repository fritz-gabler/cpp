/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/11 20:11:39 by fgabler          ###   ########.fr       */
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
#include <sstream>
#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter() : 
  type_(NOT_DEFINED),
  int_converted_(0),
  char_converted_(0),
  float_converted_(0),
  double_converted_(0) {}


ScalarConverter::ScalarConverter(const ScalarConverter &other) :
  type_(other.type_),
  int_converted_(other.char_converted_),
  char_converted_(other.int_converted_),
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

  converter.set_type(input);
  if (converter.get_type() == NOT_DEFINED)
    return (log("Input is not definable", ERROR));
  converter.convert_all_types(input);
  converter.print_converted_types();
}

void ScalarConverter::set_type(const std::string &input)
{
  if (input == "nan" || input == "nanf")
    type_ = NOT_A_NUMBER;
  else if (input == "+inf" || input == "+inff")
    type_ = POS_INF;
  else if (input == "-inf" || input == "-inff")
    type_ = NEG_INF;
  else if (is_integer(input) == true)
    type_ = INT;
  else if (std::isalpha(input[0]) != false && input.size() == 1)
    type_ = CHAR;
  else if (is_float(input) == true)
    type_ = FLOAT;
  else if (is_double(input) == true)
    type_ = DOUBLE;
  else
    type_ = NOT_DEFINED;
}

bool ScalarConverter::is_integer(const std::string &input) const
{
  if (std::isdigit(input[0]) == false && (input[0] != '-' && input[0] != '+'))
    return (false);
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (i == 0 && (input[i] == '-' && input[i] == '+'))
      i++;
    if (std::isdigit(input[i]) == false)
      return (false);
  }
  return (true);
}

bool ScalarConverter::is_float(const std::string &input) const
{
  if (input[input.size() - 1] != 'f')
    return (false);
  bool decimal_point_found = false;
  for (unsigned long i = 0; i < (input.size() - 1); i++)
  {
    if (input[i] == '.' && decimal_point_found == false)
    {
      decimal_point_found = true;
      i++;
    }
    if (std::isdigit(input[i]) == false)
      return (false);
  }
  return (true);
}

bool ScalarConverter::is_double(const std::string &input) const
{
  bool decimal_point_found = false;
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (input[i] == '.' && decimal_point_found == false)
    {
      decimal_point_found = true;
      i++;
    }
    if (std::isdigit(input[i]) == false)
      return (false);
  }
  return (true);
}

ScalarConverter::t_type ScalarConverter::get_type() const
{
  return (type_);
}

void ScalarConverter::convert_all_types(const std::string &input)
{
  switch (type_)
  {
    case CHAR:
      char_convert(input);
      break;
    case INT:
      convert_number(input);
      break;
    case FLOAT:
      convert_number(input);
      break;
    case DOUBLE:
      convert_number(input);
      break;
    case NOT_A_NUMBER:
    case NEG_INF:
    case POS_INF:
    case NOT_DEFINED:
      break;
  }
}

void ScalarConverter::char_convert(const std::string &input)
{
    if (std::isprint(input[0]) == false)
      error_message_[CHAR] = "Non displayable";
    else
      char_converted_ = static_cast<char>(input[0]);
    int_converted_ = static_cast<int>(input[0]);
    float_converted_ = static_cast<float>(input[0]);
    double_converted_ = static_cast<double>(input[0]);
}

void ScalarConverter::convert_number(const std::string &input)
{
  std::string number_to_convert;

  if (type_ == FLOAT)
    std::memcpy(&number_to_convert, &input, input.size());
  else
    std::memcpy(&number_to_convert, &input, input.size() + 1);

  std::istringstream convert(input);

  if (is_in_int_range(input) == false)
    error_message_[INT] = "impossible";
  else
  {
    convert >> int_converted_;
    convert.clear();
    convert.str(number_to_convert);
  }

  if (std::isprint(int_converted_) != false)
    char_converted_ = static_cast<char>(int_converted_);
  else if (int_converted_ < 0 || int_converted_ > 127)
    error_message_[CHAR] = "impossible";
  else if (std::isprint(int_converted_) == false)
    error_message_[CHAR] = "Non displayable";

  convert >> float_converted_;
  convert.clear();
  convert.str(number_to_convert);

  convert >> double_converted_;
}

bool ScalarConverter::is_in_int_range(const std::string &input) const
{
  std::istringstream convert_check(input);
  if (input.size() > 11)
    return (false);
  long int number;

  convert_check >> number;
  if (number < std::numeric_limits<int>::min()
      || number > std::numeric_limits<int>::max())
    return (false);
  return (true);
}


void ScalarConverter::print_converted_types() const
{
  if (error_message_[CHAR] == "")
    std::cout << "char: " << char_converted_ << std::endl;
  else
    std::cout << "char: " << error_message_[CHAR] << std::endl;

  if (error_message_[INT] == "")
    std::cout << "int: " << int_converted_ << std::endl;
  else
    std::cout << "int: " << error_message_[INT] << std::endl;

  if ((fmod(float_converted_, 1.0) == 0) && error_message_[FLOAT] == "")
    std::cout << std::fixed << std::setprecision(1);

  if (error_message_[FLOAT] == "")
    std::cout << "float: " << float_converted_ << "f" <<  std::endl;
  else
    std::cout << "float: " << error_message_[FLOAT] << std::endl;

  if (error_message_[DOUBLE] == "")
    std::cout << "double: " << float_converted_ <<  std::endl;
  else
    std::cout << "double: " << error_message_[INT] << std::endl;

}
