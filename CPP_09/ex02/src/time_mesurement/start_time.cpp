/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_time.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:44:02 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/10 21:47:23 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

void start_time(clock_t &time)
{
  time = clock();
}
