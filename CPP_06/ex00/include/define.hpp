#ifndef DEFINE_HPP
#define DEFINE_HPP

typedef enum e_colors
{
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

typedef enum e_log_level
{
  TEST = 0,
  WARNING = 1,
  ERROR = 2,
  NOTE = 3,
  EXCEPTION = 4
} t_log_level;

#define MIN_PRINTABLE 32
#define MAX_PRINTABLE 126

#endif
