#ifndef DEFINE_HPP
#define DEFINE_HPP

// LEVELS
typedef enum e_print_level
{
  TEST = 0,
  WARNING = 1,
  ERROR = 2,
  NOTE = 3,
  EXCEPTION = 4
} s_print_levels;

typedef enum e_forms
{
  PRESIDENTIAL_FORM = 0,
  ROBOTO_FORM = 1,
  SHRUBBERY_FORM = 2
} s_forms;

#define NUMBER_OF_FORMS 3
#define SAME_STRING 0

#endif
