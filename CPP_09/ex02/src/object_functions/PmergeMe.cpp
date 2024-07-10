/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:43:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/09 21:01:02 by fgabler          ###   ########.fr       */
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
  orphan_ = 0;
  save_possible_orphan_number();
  size_input_ = input.size();
  create_insertion_order();
  /*
     std::vector<unsigned int>::iterator it =  insertion_order.begin();
  for (; it != insertion_order.end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  */
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

  for (size_t i = 0, idx = *j_it; i < ((input_.size() / 2) - 1); i++)
  {
    insertion_order.push_back(idx - 1);
    set_idx_position(j_it, idx);
  }
}

void PmergeMe::set_idx_position(std::vector<unsigned int>::const_iterator &it,
    size_t &idx)
{
  if (idx - 1 == *(it - 1)) // idx == 2 - 1 = 1 | < jacob == 1 
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
    std::cout << tmp_jacobsthal << " ";
  }
  std::cout << std::endl;
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
  create_internally_sorted_pairs(vector_to_sort_);
  sort_pairs(vector_to_sort_);
  first_element_insert_in_sequence(vector_to_sort_);
  sort_larger_number_in_sequence(vector_to_sort_);
  insert_in_sequence(vector_to_sort_);

  /*
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
  */
  return (sequence_);
}

template<typename T>
void PmergeMe::create_internally_sorted_pairs(T &container)
{
  std::vector<unsigned int>::const_iterator it;
  std::vector<unsigned int>::const_iterator end_node = input_.end();

  for (it = input_.begin(); it != end_node && it + 1 != end_node; it += 2)
  {
    std::vector<unsigned int> pair_to_add;
    pair_to_add.push_back(*it);
    if (pair_to_add.front() > *(it + 1))
      pair_to_add.push_back(*(it + 1));
    else
      pair_to_add.insert(pair_to_add.begin(), *(it + 1));
    container.push_back(pair_to_add);
  }
}

template<typename T>
void PmergeMe::sort_pairs(T &container)
{
  if (container.size() == 1)
    return;

  size_t mid = container.size() / 2;
  T left(container.begin(), container.begin() + mid);
  T right(container.begin() + mid, container.end());
  sort_pairs(left);
  sort_pairs(right);

  std::merge(left.begin(), left.end(), right.begin(), right.end(),
                                                       container.begin());
}

template<typename T>
void PmergeMe::sort_larger_number_in_sequence(T &container)
{
  typename T::const_iterator it;

  for (it = container.begin(); it != container.end(); it++)
  {
    sequence_.push_back((*it).front());
  }
}

template<typename T>
void PmergeMe::first_element_insert_in_sequence(T &container)
{
  sequence_.push_back(container[0][1]);
}

template<typename T>
void PmergeMe::insert_in_sequence(T &container)
{
  std::vector<unsigned int>::iterator position_insertion;
  int amount_inserted_elements = 1; // -1 | 0 1 2
  for(unsigned int idx = 0; idx != container.size() - 1; idx++)
  {
    int window = (insertion_order[idx]) + amount_inserted_elements;

    int insertion_idx = insertion_order[idx];

    int element_to_insert = container[insertion_idx][1];

    position_insertion = std::upper_bound(sequence_.begin(),
                              sequence_.begin() + window, element_to_insert);

    sequence_.insert(position_insertion, element_to_insert);
    amount_inserted_elements++;
  }
}

void PmergeMe::insert_possible_orphan()
{
  if (orphan_ == 0)
    return ;
  std::vector<unsigned int>::iterator insert_position =
    std::upper_bound(sequence_.begin(), sequence_.end(), orphan_);

  sequence_.insert(insert_position, orphan_);
}

