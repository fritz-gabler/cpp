/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_convertible_to_int.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:29:18 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/19 18:54:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static bool is_str_digit(const std::string &str);
static void is_first_char_minus_or_plus(const std::string &str, int &i);
static bool is_str_in_int_range(const std::string &str);

bool is_str_convertible_to_int(const std::string &str) {

  if (is_str_digit(str) == false && is_str_in_int_range(str) == false)
    return (false);
  return (true);
}

static bool is_str_digit(const std::string &str)
{
  for (int i = 0; str[i] != '\0'; i++) {
    is_first_char_minus_or_plus(str, i);
    if (std::isdigit(str[i]) != false)
      return (false);
  }
  return (true);
}

static void is_first_char_minus_or_plus(const std::string &str, int &i) {
  if ((str[0] == '-' || str[0] == '+') && i == 0)
    i++;
}

static bool is_str_in_int_range(const std::string &str)
{
  //long int number_to_check_int;

  if(str.length() > 11)
    return (false);
  //number_to_check_int = std::stol(str);
  //if (number_to_check_int > INT_MAX || number_to_check_int < INT_MIN)
  //j  return (false);
  return (true);
}
