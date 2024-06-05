/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_smalest_and_longest_span.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:59:52 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/05 12:25:48 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "header.hpp"
#include "define.hpp"

void test_smalest_and_longest_span()
{
  std::string message;

  std::cout << "\n";
  message = "-------TEST SMALEST AND LONTEST SPAN-------\n";
  log(message, NOTE);

  Span numbers(4);
  numbers.add_number(3);
  numbers.add_number(10);
  numbers.add_number(6);
  numbers.add_number(15);

  log("Print SMALEST SPAN", TEST);
  std::cout << "SMALEST SPAN: " << numbers.shortest_span() << std::endl;
  log("Print LONGEST SPAN", TEST);
  std::cout << "LONTEST SPAN: " << numbers.longest_span() << std::endl;
}
