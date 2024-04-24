/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:55:34 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/24 09:10:51 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void) {
  Point Apoint(0, 0);
  Point Bpoint(10, 0);
  Point Cpoint(6, 8);

  Point checkPointOne(2.4f, 2.9);
  std::cout << "Triangle points:"
            << "\nA ( x = 0 | y = 0 )"
            << "\nB ( x = 10 | y = 0 )"
            << "\nC ( x = 6 | y = 8 )\n";
  std::cout << "Point to check P ( x = 2.4 | y = 2.9)\n";
  if (bsp(Apoint, Bpoint, Cpoint, checkPointOne) == true)
    std::cout << "point is in range of triangle" << std::endl;
  else
    std::cout << "point is NOT in range of triangle" << std::endl;
  return 0;
}
