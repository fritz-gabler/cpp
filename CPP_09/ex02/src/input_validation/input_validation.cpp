/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:31:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/06 16:57:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "define.hpp"
#include <sstream>
#include "header.hpp"


static bool is_a_positive_digit(const std::string &input);
static bool input_with_in_u_int_limits(const std::string &input);

bool input_validation(const std::string &input)
{
  if (is_a_positive_digit(input) == false)
  {
    log(NOT_DIGIT_MESSAGE, ERROR);
    return (false);
  }
  else if (input_with_in_u_int_limits(input) == false)
  {
    log(OVERFLOW_MESSAGE, ERROR);
    return (false);
  }
  return (true);
}

static bool is_a_positive_digit(const std::string &input)
{
  for (int i = 0; input[i] != 0; i++)
  {
    if (isdigit(input[i]) == false)
      return (false);
  }
  return (true);
}

static bool input_with_in_u_int_limits(const std::string &input)
{
  std::stringstream convert;
  long unsigned int number;

  for (int i = 0; input[i] != '\0'; i++)
  {
    convert >> number;
    if (number > std::numeric_limits<unsigned int>::max())
      return (false);
  }
  return (true);
}
