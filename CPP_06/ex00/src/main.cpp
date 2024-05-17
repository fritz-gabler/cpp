/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:51:11 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/17 11:21:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
  if (input_parsing(ac, av) == false)
    return (0);
  ScalarConverter::convert(av[1]);
  static_cast<void>(av);
  return (0);
}
