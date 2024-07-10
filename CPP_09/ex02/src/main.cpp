/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:38:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/10 21:15:27 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <vector>

int main(int ac, char **av)
{
  if (ac < 2)
  {
    log(WRONG_ARGS, ERROR);
    return (false);
  }
  else if (input_validation(av, ac) == false)
    return (false);

  std::vector<unsigned int> input;
  convert_input(ac, av, input);
  std::vector<unsigned int>::iterator it = input.begin();
  for (; it != input.end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "hallo\n";
  PmergeMe test_class(input);
  test_class.vector_merge_insertion_sort();
  test_class.deque_merge_insertion_sort();
  return (true);
}
