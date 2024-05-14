/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capitalize_string.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:10:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/14 08:17:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void  capitalize_string(const std::string &str, std::string &destination)
{
  destination.resize(str.size());

  for(int i = 0; str[i] != '\0'; i++)
  {
    destination[i] = std::toupper(str[i]);
  }
}
