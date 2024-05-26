/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:27:52 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/26 18:06:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <vector>
#include "define.hpp"

int main()
{
  std::cout << "\n";
  log("Create vector<int> with 10 elements from 1 - 10", NOTE);
  std::vector<int>int_vector;

  for(int i = 0; i < 10; i++)
    int_vector.push_back(i);

  log("Try to find number 3", TEST);
  if (easyfind(int_vector, 3) == true)
    log("Number 3 is in vector\n", NOTE);
  else
    log("Number 3 is NOT in vector\n", ERROR);

  log("Try to find number 15", TEST);
  if (easyfind(int_vector, 15) == true)
    log("Number 15 is in vector\n", NOTE);
  else
    log("Number 15 is NOT in vector\n", ERROR);
  return (0);
}
