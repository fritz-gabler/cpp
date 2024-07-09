/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:38:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/09 22:21:52 by fgabler          ###   ########.fr       */
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

  for (int i = 0; i < 20; i++)
  {
    if (i < 3)
      test.push_back(i + 23);
    else
      test.push_back(i + 3);
  }
  std::vector<unsigned int>::iterator it;
  for(it = test.begin(); it != test.end(); it++)
  {
    std::cout << *it << " ";
  }

  std::cout << std::endl;
  std::cout << std::endl;

  PmergeMe test_class(test);
  test_class.vector_merge_insertion_sort();
  return (true);
}
