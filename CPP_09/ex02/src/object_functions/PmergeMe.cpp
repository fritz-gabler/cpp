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
  save_possible_orphan_number();
  size_input_ = input.size();
  create_insertion_order();
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
  input_ = other.input_;
  size_input_ = other.size_input_;
  insertion_order = other.insertion_order;
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
void PmergeMe::create_insertion_order()
{
  std::vector<unsigned int> jacobsthal_number;
  build_jacopsthal_number(jacobsthal_number);
  std::vector<unsigned int>::const_iterator j_it
                                              = jacobsthal_number.begin() + 1;
  for (size_t i = 0, idx = *j_it; i < (input_.size() / 2); i++)
  {
    insertion_order.push_back(idx - 1);
    set_idx_position(j_it, idx);
  }
}

void PmergeMe::set_idx_position(std::vector<unsigned int>::const_iterator &it,
    size_t &idx)
{
  if (idx - 1 == *(it - 1))
  {
    idx = *(++it);
    if (idx > size_input_ / 2)
      idx = size_input_ / 2;
  }
  else
    idx--;
}


void PmergeMe::build_jacopsthal_number(std::vector<unsigned int> &j_thal)
{
  size_t tmp_jacobsthal = 0;
  for (unsigned int i = 2; tmp_jacobsthal <= ((size_input_ / 2) - 1); ++i)
  {
    tmp_jacobsthal = compute_jacobsthal_number(i);
    j_thal.push_back(tmp_jacobsthal);
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
  sort_larger_and_first_smaller_nums_in_sequence(vector_to_sort_);
  sort_pairs(vector_to_sort_);

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
