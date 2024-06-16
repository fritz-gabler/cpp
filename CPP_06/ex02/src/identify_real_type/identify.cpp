/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:31:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/16 17:49:57 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "define.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include "Base.hpp"

void identify(Base *p)
{
  if (dynamic_cast<A*>(p) != NULL)
    log("The actual type of the object pointed to by p: A", NOTE);
  else
    log("Base type pointer is not sub class A", ERROR);

  if (dynamic_cast<B*>(p) != NULL)
    log("The actual type of the object pointed to by p: B", NOTE);
  else
    log("Base type pointer is not sub class B", ERROR);

  if (dynamic_cast<C*>(p) != NULL)
    log("The actual type of the object pointed to by p: C", NOTE);
  else
    log("Base type pointer is not sub class C", ERROR);

}

void identify(Base &p)
{
  try
  {
    A test_a = dynamic_cast<A&>(p);
    log("The actual type reference of the object pointed to by p: A", NOTE);
  }
  catch (std::exception &exception)
  {
    log("Base type reference is not sub class A", EXCEPTION);
  }
  try
  {
    B test_b = dynamic_cast<B&>(p);
    log("The actual type reference of the object pointed to by p: B", NOTE);
  }
  catch (std::exception &exception)
  {
    log("Base type reference is not sub class B", EXCEPTION);
  }
  try
  {
    C test_c = dynamic_cast<C&>(p);
    log("The actual type reference of the object pointed to by p: C", NOTE);
  }
  catch (std::exception &exception)
  {
    log("Base type reference is not sub class C", EXCEPTION);
  }
}
