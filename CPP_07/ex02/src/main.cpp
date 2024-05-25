/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:59:54 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/25 14:25:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "define.hpp"
#include "header.hpp"

int main() {
  Array<int> array(42);

  log("Create int array with size 42, now we check by calling the array.size() "
      "function\n", NOTE);
  std::cout << array.size() << std::endl;

  log("Fill int array with number 42", NOTE);
  for (int i = 0; i < 42; i++) {
    array[i] = 42;
  }
  log("Check if filling worked", NOTE);
  for (int i = 0; i < 42; i++) {
    std::cout << i << ": " << array[i] << std::endl;
  }

  std::cout << "\n";
  log("Try to access list at 43 member", NOTE);
  try {
    array[42];
  } catch (std::exception &exception) {
    log("Accessing 43 member of array failed and was throwing an exception " , ERROR);
    std::cout << "Because: " << exception.what() << "\n";
  }
  return (0);
}
