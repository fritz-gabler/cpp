/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/19 10:23:43 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "define.hpp"
#include "functions.hpp"
#include <cstdlib>
#include <cstring>
#include <limits.h>
#include <stdlib.h>

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
}

void ScalarConverter::char_print_if_possible(const std::string &input) {
  if (is_valid_char(input) == false)
    std::cout << "char: " + message_;
  else
    std::cout << "char: '" << static_cast<char>(atoi(input.c_str())) << "'\n";
}

bool ScalarConverter::is_valid_char(const std::string &input) {
  if (is_special_double_value(input) == true ||
      is_special_float_value(input) == true)
    return (message_ = "impossible\n", false);
  for (int i = 0; input[i] != '\0'; i++) {
    if (std::isprint(input[i]) == false)
      return (message_ = "Non displayable\n", false);
  }
  return (false);
}

void ScalarConverter::int_print_if_possible(const std::string &input) {
  static_cast<void>(input);
}

bool ScalarConverter::is_special_double_value(const std::string &input) {
  if (input == "-inf" || input == "+inf")
    return (true);
  if (input == "nan")
    return (true);
  return (false);
}

bool ScalarConverter::is_special_float_value(const std::string &input) {
    return (true);
  if (input == "nanf")
    return (true);
  return (false);
}

std::string ScalarConverter::message_ = "impossible";
