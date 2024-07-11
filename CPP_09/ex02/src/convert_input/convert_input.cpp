/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:06:15 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 09:51:36 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <vector>
#include <iostream>

void convert_input(int ac, char **av,
                                    std::vector<unsigned int> &converted_input)
{
  std::stringstream convert;
  for (int i = 1; i < ac; i++)
  {
    convert.str(av[i]);
    unsigned int number_converted;
    convert >> number_converted;
    converted_input.push_back(number_converted);
    convert.clear();
  }
}
