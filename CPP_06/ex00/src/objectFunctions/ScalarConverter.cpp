/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/17 00:05:46 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "define.hpp"
#include <cstring>
#include "functions.hpp"
#include "climits"


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

void ScalarConverter::convert(const std::string &input)
{
  char_print_if_possible(input);
}

void ScalarConverter::char_print_if_possible(const std::string &input)
{
  if (is_valide_char(input) == false)
    std::cout << "char: impossible\n";
  else
    std::cout << "char: " + input + "\n";
}

bool ScalarConverter::is_valide_char(const std::string &input)
{
  if (std::strlen(input.c_str()) != 1)
    return (false);
  else if (input[0] < MIN_ASCII_PRINTABLE || input[0] > MAX_ASCII_PRINTABLE)
    return (false);
  return (true);
}

void ScalarConverter::int_print_if_possible(const std::string &input)
{
  if (input < INT_MIN)
}
