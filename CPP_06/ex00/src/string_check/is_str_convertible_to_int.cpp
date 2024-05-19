/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_convertible_to_int.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:29:18 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/19 11:52:08 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static bool is_first_char_minus_or_plus(std::string &str, int i);

bool is_str_convertible_to_int(std::string &str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (is_first_char_minus_or_plus(str, i) == true)
      i++;
    if (std::isdigit(str[i]) != false)
      return (false);
  }

  long int number_to_check_int;

  number_to_check_int = std::stol(str);
  if (number_to_check_int > INT_MAX || number_to_check_int < INT_MIN)
    return (false);
  return (true);
}

static bool is_first_char_minus_or_plus(std::string &str, int i) {
  if ((str[0] == '-' || str[0] == '+') && i == 0)
  return (true);
  return (false);
}
