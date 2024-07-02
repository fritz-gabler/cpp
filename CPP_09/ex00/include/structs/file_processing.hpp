#ifndef FILE_PROCESSING_HPP
#define FILE_PROCESSING_HPP

#include <fstream>


typedef struct s_file_processing
{
  std::ifstream file;
  std::string line;
  std::string separated_str[2];
  int date_saved;
  float value_saved;
  float value_to_print;
  float multiply_value;

}  t_file_processing;

#endif
