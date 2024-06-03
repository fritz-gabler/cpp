/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:19:38 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/03 17:32:46 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
  numbers_.reverse(N);
}


