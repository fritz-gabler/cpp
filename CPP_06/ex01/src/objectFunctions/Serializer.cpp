/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:04:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/23 13:34:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdio>
#include "Data.hpp"


///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &) {}

Serializer &Serializer::operator = (const Serializer &) { return *this; }

Serializer::~Serializer() {}


///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

uintptr_t Serializer::serialize(Data *ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data*>(raw));
}
