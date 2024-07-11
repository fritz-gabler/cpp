/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_check.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:05:45 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 10:30:02 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <iostream>
#include <sys/time.h>

void deque_check(std::vector<unsigned int> &input)
{
  time_t time;
  start_time(time);

  PmergeMe deque_class(input);
  deque_class.deque_merge_insertion_sort();

  double duration;
  get_stopped_time(time, duration);

  std::cout << "Time to process a range of "
    << input.size()
    << "  elements with std::deque : "
    << duration 
    << " μs."
    << std::endl;
}

