/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:35:09 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/24 13:04:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main()
{
  std::string array[] = {"fist", "second", "third"};
  int size_of_array = 3;
  iter(array, size_of_array, print);
  return (0);
}
