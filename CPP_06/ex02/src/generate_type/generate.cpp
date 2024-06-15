/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:31:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/15 12:05:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>
#include "header.hpp"

Base *generate(void)
{
  int number = rand();

  if ((number % 3) == 0)
  {
    log("GENERATED: subclass A\n", NOTE);
    return (new A);
  }
  if ((number % 3) == 1)
  {
    log("GENERATED: subclass B\n", NOTE);
    return (new B);
  }
  if ((number % 3) == 2)
  {
    log("GENERATED: subclass C\n", NOTE);
    return (new C);
  }
  return (NULL);
}
