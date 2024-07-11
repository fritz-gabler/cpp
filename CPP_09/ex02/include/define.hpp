/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:58:11 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/11 09:29:30 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_HPP
#define DEFINE_HPP

// ENUMS

typedef enum e_colors {
  red = 0,
  dark_green = 1,
  gress_green = 2,
  yellow = 3,
  magenta = 4,
  blue = 5,
  white = 6,
  orange = 7,
  reset = 8
} t_colors;

typedef enum e_log_level {
  TEST = 0,
  WARNING = 1,
  ERROR = 2,
  NOTE = 3,
  EXCEPTION = 4
} t_log_level;

// NUMBER DEFINES

#define MIN_PRINTABLE 32
#define MAX_PRINTABLE 126

// MESSAGES
#define WRONG_ARGS "wrong number of arguments, please input int numbers"
#define NOT_DIGIT_MESSAGE "input can just consitst of positive digits"
#define OVERFLOW_MESSAGE "one inputted number is bigger than UINT_MAX"
#define IS_SORTED_ALREADY "input is already sorted"



#endif
