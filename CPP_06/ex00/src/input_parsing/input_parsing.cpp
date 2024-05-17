/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:50:52 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/17 07:52:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

bool input_parsing(int ac) {
  if (ac != 2) {
    log("Wrong number of parameter: ./scalar_converter oneArgument", ERROR);
    return (false);
  }
  return (true);
}
