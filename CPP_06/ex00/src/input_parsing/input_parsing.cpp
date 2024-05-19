/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:50:52 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/19 11:22:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <cctype>

static bool is_number_in_str(char *str);
static bool is_alpha_in_str(char *str);

bool input_parsing(int ac, char **av) {
  if (ac != 2) {
    log("Wrong number of parameter: ./scalar_converter oneArgument", ERROR);
    return (false);
  }
  if (is_number_in_str(av[1]) == true && is_alpha_in_str(av[1]) == true)
  {
    log("Mixed input: mixing numbers and alphabeticals is invalide", ERROR);
    return (false);
  }
  return (true);
}

static bool is_number_in_str(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (std::isdigit(str[i]) != false)
      return (true);
  }
  return (false);
}

static bool is_alpha_in_str(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (std::isalpha(str[i]) != false)
      return (true);
  }
  return (false);
}
