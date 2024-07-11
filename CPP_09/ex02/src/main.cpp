/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:38:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 09:56:58 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <vector>
#include <time.h>
#include <iomanip>

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

  clock_t time;
  double duration;
  
  start_time(time);
  PmergeMe vector_class(input);
  vector_class.vector_merge_insertion_sort();
  get_stopped_time(time, duration);
  std::cout << duration << std::endl;

  start_time(time);
  PmergeMe deque_class(input);
  vector_class.deque_merge_insertion_sort();
  get_stopped_time(time, duration);
  std::cout << duration << " μs."<< std::endl;
  return (true);
}
