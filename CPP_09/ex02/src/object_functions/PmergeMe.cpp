/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:43:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/06 21:41:47 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cctype>
#include "define.hpp"
#include <sstream>
#include <vector>
#include <cmath>

/////////////////////////CONSTRUCTOR AND DESTRUCTOR////////////////////////////

PmergeMe::PmergeMe(const std::vector<unsigned int> &input)
{
  input_ = input;
  size_input_ = input_.size();
  build_jacopsthal_number();
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
  input_ = other.input_;
  size_input_ = other.size_input_;
  jacobs_thal_number_ = other.jacobs_thal_number_;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &other)
{
  if (this != &other)
    *this = other;
  return (*this);
}

PmergeMe::~PmergeMe() {};

///////////////////////////////MEMBER FUNCTIONS////////////////////////////////

void PmergeMe::build_jacopsthal_number()
{
  size_t tmp_jacobsthal = 0;
  for (unsigned int i = 3; tmp_jacobsthal <= size_input_; ++i)
  {
    tmp_jacobsthal = compute_jacobsthal_number(i);
    jacobs_thal_number_.push_back(tmp_jacobsthal);
  }
}

size_t PmergeMe::compute_jacobsthal_number(unsigned int n)
{
  return (pow(2, n) - pow(-1, n)) / 3;
}

std::vector<unsigned int> &PmergeMe::deque_merge_insertion_sort()
{
  return (sequence_);
}

std::vector<unsigned int> &PmergeMe::vector_merge_insertion_sort()
{
  return (sequence_);
}

void PmergeMe::save_possible_orphan_number()
{
  if (size_input_ % 2 != 0)
    return ;
  orphan_ = input_.back();
  input_.pop_back();
  return ;

}
