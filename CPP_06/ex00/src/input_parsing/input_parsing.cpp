/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:50:52 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/17 17:46:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <cctype>

static bool is_str_number(char *str);
static bool is_str_alpha(char *str);

bool input_parsing(int ac, char **av) {
  if (ac != 2) {
    log("Wrong number of parameter: ./scalar_converter oneArgument", ERROR);
    return (false);
  }
  else if (is_str_number(av[1]) == true && is_str_alpha(av[1]) == true)
  {
    log("Mixed input: mixing numbers and alphabeticals is invalide", ERROR);
    return (false);
  }
  return (true);
}

static bool is_str_number(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (std::isdigit(str[i]) == false)
      return (false);
  }
  return (true);
}

static bool is_str_alpha(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (std::isalpha(str[i]) == false)
      return (false);
  }
  return (true);
}
