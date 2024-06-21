/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_more_numbers_than_available_space.cpp          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:31:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/21 17:46:50 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "header.hpp"

void add_more_numbers_than_available_space()
{
  std::string message;

  message = "--------TEST ADDING MORE NUMBERS THAT SPACE AVAILABLE---------";
  log(message, TEST);

  Span add_to_much(2);

  try
  {
    for (int i = 0; i < 3; i++)
      add_to_much.add_number(i);
    message = "adding numbers worked";
    log(message, TEST);
  }
  catch(const std::exception &e)
  {
    message = static_cast<std::string>(e.what());
    log(message, EXCEPTION);
  }

}
