/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:20:45 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/12 13:50:44 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdio>
#include "define.hpp"
#include "header.hpp"

int main()
{
  Data test_data;
  uintptr_t save_serialized_value;

  log("-------PDF TEST--------", TEST);
  log("Print number and ptr before casting", NOTE);

  test_data.print_this_ptr();
  test_data.print_a_fun_number();
  save_serialized_value = Serializer::serialize(&test_data);
  Serializer::deserialize(save_serialized_value);
  log("Print number and ptr after casting", NOTE);
  test_data.print_this_ptr();
  test_data.print_a_fun_number();
}
