/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:12:42 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/23 20:25:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
  for (int i = 0; i < 10; i++)
  {
    std::cout << "\n";
    Base *test = generate();
    log("Identify pointer: ", TEST);
    identify(test);
    log("Identify reference: ", TEST);
    identify(&(*test));
    delete test;
  }
  return (0);
}
