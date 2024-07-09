/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:43:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/07 19:53:20 by fgabler          ###   ########.fr       */
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

void PmergeMe::save_possible_orphan_number()
{
  if ((input_.size() + 1) % 2 != 0)
    return ;
  orphan_ = input_.back();
  input_.pop_back();
  return ;
}
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
  create_internally_sorted_pairs(deque_to_sort_);
  return (sequence_);
}

std::vector<unsigned int> &PmergeMe::vector_merge_insertion_sort()
{
  create_internally_sorted_pairs(vector_to_sort_);
  sort_larger_and_first_smmaler_nums_in_sequence(vector_to_sort_);

  std::vector<std::vector<unsigned int> >::iterator it;
  for (it = vector_to_sort_.begin(); it != vector_to_sort_.end(); it++)
  {
    std::cout << "pair: " << (*it).front() << " " << (*it).back() << std::endl;
  }
  std::cout << std::endl << std::endl;

  std::vector<unsigned int>::iterator it_s;

  for (it_s = sequence_.begin(); it_s != sequence_.end(); it_s++)
  {
    std::cout << *it_s << " ";
  }
  std::cout << std::endl;
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
