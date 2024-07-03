/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:38:24 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/03 17:44:52 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "header.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
    return (log(WRONG_ARGS, ERROR), 0);
  
  RPN polish_notation;

  polish_notation.calculate(av[1]);
  return (0);
}
