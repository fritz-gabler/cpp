/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:19:04 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/20 10:23:30 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "define.hpp"

bool input_check(int ac)
{
  if (ac == 2)
    return (true);
  log(WRONG_ARGS, ERROR);
  return (false);
}
