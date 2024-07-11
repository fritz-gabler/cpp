/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:38:24 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 18:32:33 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "header.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
    return (log(WRONG_ARGS, ERROR), 0);
  
  RPN polish_notation;

  try
  {
    polish_notation.calculate(av[1]);
  }
  catch (const std::exception &exception)
  {
    std::cout << exception.what() << std::endl;
  }
  return (0);
}
