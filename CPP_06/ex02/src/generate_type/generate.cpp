/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:31:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/23 20:12:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void)
{
  int number = std::rand();

  if ((number % 3) == 0)
    return (new A);
  if ((number % 3) == 1)
    return (new B);
  if ((number % 3) == 2)
    return (new C);
  return (NULL);
}
