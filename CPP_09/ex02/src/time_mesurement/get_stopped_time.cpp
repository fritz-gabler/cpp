/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stopped_time.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:47:27 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 09:53:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

void get_stopped_time(clock_t &start_time, double &duration)
{
  clock_t end_time = clock();
  duration = static_cast<double>(end_time - start_time)
                                                / CLOCKS_PER_SEC * 1000000;
}
