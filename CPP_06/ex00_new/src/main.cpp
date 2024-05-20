/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:51:11 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/20 10:18:16 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
    return (0);
  ScalarConverter::convert(av[1]);
  return (0);
}
