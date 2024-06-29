/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:21:21 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/28 19:21:29 by fgabler          ###   ########.fr       */
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
  Date test_date;
  test_date.set_date("2000-02-10");
  return (0);
}
