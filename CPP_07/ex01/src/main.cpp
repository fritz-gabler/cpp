/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:35:09 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/25 09:09:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "define.hpp"

int main()
{
  std::string str_array[] = {"fist", "second", "third"};
  int number_array[] = {7, 4, 6, 9, 4, 2};
  int str_size_of_array = 3;
  int number_size_of_array = 6;
  log("Input string array and a function to print str array, in iter function", NOTE);
  iter<std::string>(str_array, str_size_of_array, print_str);
  log("Input number array and a function to print numbers array, in iter function", NOTE);
  iter<int>(number_array, number_size_of_array, print_int);
  return (0);
}
