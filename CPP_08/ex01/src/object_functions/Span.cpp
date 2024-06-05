/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:19:38 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/05 12:28:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "stdlib.h"
#include <algorithm>

///////////////////////////////CONSTRUCOR DESTRUCTOR///////////////////////////

Span::Span(const Span &other)
{
  *this = other;
}

Span &Span::operator = (const Span &other)
{
  if (this != &other)
  {
    numbers_ = other.numbers_;
    size_ = other.size_;
  }
  return (*this);
}

Span::Span(unsigned int N) : size_(N)
{
  numbers_.reserve(N);
}

Span::~Span() {}


/////////////////////////////////MEMBERFUNCTIONS///////////////////////////////

void Span::add_number(int N)
{
  if (numbers_.size() == size_)
    throw no_space_left_in_span_class();
  numbers_.push_back(N);
}

int Span::longest_span()
{
  if (numbers_.size() < 2)
    throw less_than_two_elements_no_span_calc_possible();

  int min;
  int max;
  int longest_span;

  min = *std::min_element(numbers_.begin(), numbers_.end());
  max = *std::max_element(numbers_.begin(), numbers_.end());

  longest_span = max - min;
  return (longest_span);
}

int Span::shortest_span()
{
  if (numbers_.size() < 2)
    throw less_than_two_elements_no_span_calc_possible();

  int min;
  int shortest_span;

  min = *std::min_element(numbers_.begin(), numbers_.end());
  shortest_span = longest_span();

  typedef std::vector<int>::iterator iterator;
  for (iterator it = numbers_.begin(); it != numbers_.end(); it++)
  {
    if (*it == min)
      it++;
    if (shortest_span > *it - min)
      shortest_span = *it - min;
  }
  return (shortest_span);
}

void Span::add_range_of_numbers(size_t range_numbers)
{
  if (numbers_.size() + range_numbers > size_)
    throw no_space_left_in_span_class();
  for (size_t i = 0; i < range_numbers; i++)
    numbers_.push_back(rand());
}

///////////////////////////////Exceptions///////////////////////////////////////

const char *Span::no_space_left_in_span_class::what() const throw()
{
  return ("No space left in span class");
}

const char *Span::less_than_two_elements_no_span_calc_possible::what()  
  const throw()
{
  return ("Less than two elements_no_span_calculation possible");
}
