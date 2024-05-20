/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/19 19:09:14 by fgabler          ###   ########.fr       */
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

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return (*this);
}

ScalarConverter::~ScalarConverter() {}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ScalarConverter::convert(const std::string &input) {
  char_print_if_possible(input);
  int_print_if_possible(input);
  float_print_if_possible(input);
  double_print_if_possible(input);
}

void ScalarConverter::char_print_if_possible(const std::string &input) {
  if (is_valid_char(input) == false) {
    std::cout << "char: " + message_;
    message_ = "impossible\n";
  }
  else
    std::cout << "char: '" << static_cast<char>(atoi(input.c_str())) << "'\n";
}

bool ScalarConverter::is_valid_char(const std::string &input) {
  if (is_special_double_value(input) == true ||
      is_special_float_value(input) == true)
    return (message_ = "impossible\n", false);

  if (std::isalpha(input[0]) != 0)
  {
    int check_number;

    check_number = atoi(input.c_str());
    if (check_number < MIN_PRINTABLE || check_number > MAX_PRINTABLE)
      return (message_ = "Non displayable\n", false);
  }
  return (true);
}

void ScalarConverter::int_print_if_possible(const std::string &input) {
  if (is_str_convertible_to_int(input) == false) {
    std::cout << "int: " << message_;
    return ;
  }
  std::cout << "int: " << static_cast<int>(std::atoi(input.c_str())) << "\n";
}

void ScalarConverter::float_print_if_possible(const std::string &input)
{
  try
  {
    float str_as_float = static_cast<float>(std::stof(input));
    if (fmod(str_as_float, 1.0) == 0)
      std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << str_as_float << "f" << std::endl;
  }
  catch (std::exception &exception)
  {
    std::cout << "float: " << message_ << std::endl;
  }
}

void ScalarConverter::double_print_if_possible(const std::string &input)
{
  try
  {
    double str_as_double = static_cast<double>(std::stof(input));
    std::cout << "double: " << str_as_double << std::endl;
  }
  catch (std::exception &exception)
  {
    std::cout << "double: " << message_ << std::endl;
  }
}

bool ScalarConverter::is_special_double_value(const std::string &input) {
  if (input == "-inf" || input == "+inf")
    return (true);
  if (input == "nan")
    return (true);
  return (false);
}

bool ScalarConverter::is_special_float_value(const std::string &input) {
  if (input == "nanf")
    return (true);
  return (false);
}

std::string ScalarConverter::message_ = "impossible\n";
