/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/20 12:04:02 by fgabler          ###   ########.fr       */
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
  input_(NULL),
  char_converted_(0),
  int_converted_(0),
  float_converted_(0),
  double_converted_(0) {}


ScalarConverter::ScalarConverter(const std::string &input) :
  input_(input),
  char_converted_(0),
  int_converted_(0),
  float_converted_(0),
  double_converted_(0) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) :
  input_(other.input_),
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
  ScalarConverter converter(input);

  if (converter.class_input_check(input))
    return ;
}

bool ScalarConverter::class_input_check(const std::string &input) const
{

  if (mixed_input(input) == true)
  {
    log(MIXED_INPUT, ERROR);
    return false;
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
