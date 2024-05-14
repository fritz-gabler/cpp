/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:10:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/14 04:52:54 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void  capitalize_string(const std::string &str, std::string &destination)
{
  for(int i = 0; str[i] != '\0'; i++)
  {
    destination[i] = str[i];
    destination[i] = std::toupper(destination[i]);
  }
}
