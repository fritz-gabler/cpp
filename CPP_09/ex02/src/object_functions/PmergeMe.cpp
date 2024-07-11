/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:43:28 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 09:50:39 by fgabler          ###   ########.fr       */
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
  if (std::is_sorted(input.begin(), input.end()) == true)
  {
    input_ = input;
    return ;
  }
  input_ = input;
  orphan_ = 0;
  save_possible_orphan_number();
  size_input_ = input.size();
  create_insertion_order();
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
  input_ = other.input_;
  size_input_ = other.size_input_;
  insertion_order_ = other.insertion_order_;
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
  if ((input_.size() / 2) <= 2)
  {
    insertion_order_.push_back(1);
    return ;
  }
  std::vector<unsigned int> jacobsthal_number;
  build_jacopsthal_number(jacobsthal_number);
  std::vector<unsigned int>::const_iterator j_it
                                              = jacobsthal_number.begin() + 1;

  for (size_t i = 0, idx = *j_it; i < ((input_.size() / 2) - 1); i++)
  {
    insertion_order_.push_back(idx - 1);
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
  }
}

size_t PmergeMe::compute_jacobsthal_number(unsigned int n)
{
  return (pow(2, n) - pow(-1, n)) / 3;
}

std::deque<unsigned int> PmergeMe::deque_merge_insertion_sort()
{
  if (deque_sequence_.empty() == false)
    return (deque_sequence_);

  create_internally_sorted_pairs(deque_to_sort_);
  sort_pairs(deque_to_sort_);
  first_element_insert_in_sequence(deque_to_sort_, deque_sequence_);
  sort_larger_number_in_sequence(deque_to_sort_, deque_sequence_);
  insert_in_sequence(deque_to_sort_, deque_sequence_);
  insert_possible_orphan(deque_sequence_);


  std::deque<std::deque<unsigned int> >::iterator it;
  for (it = deque_to_sort_.begin(); it != deque_to_sort_.end(); it++)
  {
    std::cout << "pair: " << (*it).front() << " " << (*it).back() << std::endl;
  }
  std::cout << std::endl << std::endl;

  std::deque<unsigned int>::iterator it_s;

  for (it_s = deque_sequence_.begin(); it_s != deque_sequence_.end(); it_s++)
  {
    std::cout << *it_s << " ";
  }
  std::cout << std::endl;
  return (deque_sequence_);
}

std::vector<unsigned int> &PmergeMe::vector_merge_insertion_sort()
{
  if (vector_sequence_.empty() == false)
    return input_;
  create_internally_sorted_pairs(vector_to_sort_);
  sort_pairs(vector_to_sort_);
  first_element_insert_in_sequence(vector_to_sort_, vector_sequence_);
  sort_larger_number_in_sequence(vector_to_sort_, vector_sequence_);
  insert_in_sequence(vector_to_sort_, vector_sequence_);
  insert_possible_orphan(vector_sequence_);

  std::vector<std::vector<unsigned int> >::iterator it;
  for (it = vector_to_sort_.begin(); it != vector_to_sort_.end(); it++)
  {
    std::cout << "pair: " << (*it).front() << " " << (*it).back() << std::endl;
  }
  std::cout << std::endl << std::endl;

  std::vector<unsigned int>::iterator it_s;

  for (it_s = vector_sequence_.begin(); it_s != vector_sequence_.end(); it_s++)
  {
    std::cout << *it_s << " ";
  }
  std::cout << std::endl;
  return (vector_sequence_);
}

template<typename T>
void PmergeMe::create_internally_sorted_pairs(T &container)
{
  std::vector<unsigned int>::const_iterator it;
  std::vector<unsigned int>::const_iterator end_node = input_.end();

  for (it = input_.begin(); it != end_node && it + 1 != end_node; it += 2)
  {
    typename T::value_type pair_to_add;
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

template<typename T, typename S>
void PmergeMe::sort_larger_number_in_sequence(T &container, S &sequence)
{
  typename T::const_iterator it;

  for (it = container.begin(); it != container.end(); it++)
  {
    sequence.push_back((*it).front());
  }
}

template<typename T, typename S>
void PmergeMe::first_element_insert_in_sequence(T &container, S &sequence)
{
  sequence.push_back(container[0][1]);
}

template<typename T, typename S>
void PmergeMe::insert_in_sequence(T &container, S &sequence)
{
  typename S::iterator position_insertion;
  int amount_inserted_elements = 1; // -1 | 0 1 2
  for(unsigned int idx = 0; idx != container.size() - 1; idx++)
  {
    int window = (insertion_order_[idx]) + amount_inserted_elements;

    int insertion_idx = insertion_order_[idx];

    int element_to_insert = container[insertion_idx][1];

    position_insertion = std::upper_bound(sequence.begin(),
                              sequence.begin() + window, element_to_insert);

    sequence.insert(position_insertion, element_to_insert);
    amount_inserted_elements++;
  }
}


template<typename S>
void PmergeMe::insert_possible_orphan(S &sequence)
{
  if (orphan_ == 0)
    return ;
  std::cout << "ORPHAN: " << orphan_ << std::endl;
  typename S::iterator insert_position =
    std::upper_bound(sequence.begin(), sequence.end(), orphan_);

  sequence.insert(insert_position, orphan_);
}

