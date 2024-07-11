/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:14:49 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 10:47:27 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <iostream>
#include <sys/time.h>

void vector_check(std::vector<unsigned int> &input)
{

  time_t time;
  start_time(time);

  std::vector<unsigned int> sequence;
  PmergeMe vector_class(input);
  sequence = vector_class.vector_merge_insertion_sort();

  double duration;
  get_stopped_time(time, duration);

  vector_log(sequence, input, duration);
}
