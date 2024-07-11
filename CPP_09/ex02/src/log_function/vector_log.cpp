/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_log.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:35:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 10:46:43 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <iostream>

static void output_vector_of_un_int(std::vector<unsigned int> &vec);

void vector_log(std::vector<unsigned int> sequence,
                           std::vector<unsigned int> input, double duration)
{

  std::cout << "BEFORE: ";
  output_vector_of_un_int(input);
  std::cout << "AFTER: ";
  output_vector_of_un_int(sequence);
  std::cout << "Time to process a range of "
    << input.size()
    << " elements with std::vector : "
    << duration 
    << " μs."
    << std::endl;
}


static void output_vector_of_un_int(std::vector<unsigned int> &vec)
{

  std::vector<unsigned int>::const_iterator it;

  for (it = vec.begin(); it != vec.end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
