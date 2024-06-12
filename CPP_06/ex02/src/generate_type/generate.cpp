/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:31:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/12 13:49:10 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

Base *generate(void)
{
  int number = rand();

  if ((number % 3) == 0)
    return (new A);
  if ((number % 3) == 1)
    return (new B);
  if ((number % 3) == 2)
    return (new C);
  return (NULL);
}
