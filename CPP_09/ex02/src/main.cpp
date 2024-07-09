/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:38:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/09 20:30:01 by fgabler          ###   ########.fr       */
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

  for (int i = 0; i < 10; i++)
  {
    test.push_back(i + 1);
  }
  std::cout << std::endl;
  PmergeMe test_class(test);
  test_class.vector_merge_insertion_sort();
  return (true);
}
