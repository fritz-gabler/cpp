/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:38:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/06 21:42:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(int ac, char **av)
{
  if (ac < 2)
  {
    log(WRONG_ARGS, ERROR);
    return (false);
  }
  else if (input_validation(av[1]) == false)
    return (false);

  std::vector<unsigned int> test;

  test.push_back(3);
  test.push_back(4);
  test.push_back(4);
  test.push_back(4);
  test.push_back(4);
  test.push_back(9);
  test.push_back(2);
  PmergeMe test_class(test);
  return (true);
}
