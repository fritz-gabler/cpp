/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:50:52 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/19 18:51:56 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <cctype>

static bool is_number_in_str(char *str);
static bool is_alpha_in_str(char *str);
static bool just_valid_numbers(char *str);
static bool just_valid_chars_in_str(char *str);

bool input_parsing(int ac, char **av) {
  if (ac != 2) {
    log("Wrong number of parameter: ./scalar_converter oneArgument", ERROR);
    return (false);
  }
  if (std::strlen(av[1]) <= 0) {
    log("Input to small: input got to be bigger than 0", ERROR);
    return (false);
  }
  if (is_number_in_str(av[1]) == true && is_alpha_in_str(av[1]) == true) {
    log("Mixed input: mixing numbers and alphabeticals is invalid", ERROR);
    return (false);
  }
  if (just_valid_numbers(av[1]) == false && just_valid_chars_in_str(av[1]) == false) {
      log("Mixed input: mixing numbers and alphabeticals is invalid", ERROR);
      return (false);
  }
  return (true);
}

static bool is_number_in_str(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (std::isdigit(str[i]) != false)
      return (true);
  }
  return (false);
}

static bool is_alpha_in_str(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (std::isalpha(str[i]) != false)
      return (true);
  }
  return (false);
}

static bool just_valid_numbers(char *str) {
  if (str[0] == '.')
    return (false);
  if (str[0] == '+' || str[0] == '-' || std::isdigit(str[0]) == false)
    return (true);

  int dot_found;

  dot_found = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] == '-' || str[i] == '+') && i == 0)
      i++;
    if (str[i] == '.') {
      i++;
      dot_found++;
    }
    if (std::isdigit(str[i]) == false || dot_found > 1)
      return (false);
  }
  return (true);
}

static bool just_valid_chars_in_str(char *str)
{
  for (int i = 0; str[i] != '\0'; i++) {
    if (std::isalpha(str[i]) == false)
      return (false);
  }
  return (true);
}
