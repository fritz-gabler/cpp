/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:21:21 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/28 14:31:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <iostream>

int main(int ac, char **av)
{
  if (ac != 2)
    std::cout << RED << "[ERROR]" << RESET << " Please input one file name\n";
  static_cast<void>(av);
  Date test_date;
  test_date.set_date("2024-02-1");
  return (0);
}
