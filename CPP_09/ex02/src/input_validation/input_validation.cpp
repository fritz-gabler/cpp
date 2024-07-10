/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:31:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/10 20:50:49 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "define.hpp"
#include <sstream>
#include "header.hpp"


static bool is_a_positive_digit( char **av, int ac);
static bool input_with_in_u_int_limits( char **av, int ac);
static bool is_digit_check(char *str);
static bool convert_check(char *str);

bool input_validation(char **av, int ac)
{
  if (is_a_positive_digit(av, ac) == false)
  {
    log(NOT_DIGIT_MESSAGE, ERROR);
    return (false);
  }
  else if (input_with_in_u_int_limits(av, ac) == false)
  {
    log(OVERFLOW_MESSAGE, ERROR);
    return (false);
  }
  return (true);
}

static bool is_a_positive_digit(char **av, int ac)
{
  for (int i = 1; i < ac; i++)
  {
    if (is_digit_check(av[i]) == false)
      return (false);
  }
  return (true);
}

static bool is_digit_check(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (isdigit(str[i]) == false)
      return (false);
  }
  return (true);
}

static bool input_with_in_u_int_limits( char **av, int ac)
{
  for (int i = 0; i < ac; i++)
  {
    if (convert_check(av[i]) == false)
      return (false);
  }
  return (true);
}

static bool convert_check(char *str)
{
  std::stringstream convert;
  long unsigned int number;

  convert.str(str);
  convert >> number;
  if (number > std::numeric_limits<unsigned int>::max())
    return (false);
  convert.clear();
  return (true);
}
