/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:12:42 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/15 11:56:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
  std::cout << "\n---------------------------\n\n";
  for (int i = 0; i < 3; i++)
  {
    Base *test = generate();
    log("Identify pointer: ", TEST);
    identify(test);
    std::cout << "\n";
    log("Identify reference: ", TEST);
    identify(*test);
    delete test;
    std::cout << "\n---------------------------\n\n";
  }
  return (0);
}
