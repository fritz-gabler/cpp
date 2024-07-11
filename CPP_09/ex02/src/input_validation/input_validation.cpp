/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:31:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 11:45:28 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include "define.hpp"
#include <sstream>
#include "header.hpp"
#include <vector>
#include <limits>
#include <algorithm>


static bool is_a_positive_digit( char **av, int ac);
static bool input_with_in_u_int_limits( char **av, int ac);
static bool is_digit_check(char *str);
static bool convert_check(char *str);
static bool is_already_sorted(int ac, char **av);

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
  else if (is_already_sorted(ac, av) == true)
  {
    log(IS_SORTED_ALREADY, ERROR);
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

static bool is_already_sorted(int ac, char **av)
{
  std::vector<unsigned int> converted_input;
  convert_input(ac, av, converted_input);

  for (size_t i = 0; i < converted_input.size() - 1; ++i)
  {
    if (converted_input[i] > converted_input[i + 1])
      return false;
  }
  return true;

 return (true);
}
