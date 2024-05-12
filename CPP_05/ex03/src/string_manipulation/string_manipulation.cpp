/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:10:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/11 18:49:27 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void  capitalize_string(std::string &str)
{
  for(int i = 0; str[i] != '\0'; i++)
  {
    str[i] = std::toupper(str[i]);
  }
}
