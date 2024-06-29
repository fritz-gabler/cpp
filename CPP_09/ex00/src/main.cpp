/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:21:21 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/29 14:12:59 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <iostream>
#include "define.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cout << RED_ERROR << " Please input one valide file name\n";
    return (0);
  }
  static_cast<void>(av);
  BitcoinExchange btc;
  btc.print_btc_value_for_date("some_str");
  return (0);
}
