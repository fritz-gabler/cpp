/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/02 20:24:16 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include "define.hpp"
#include "sstream"
#include "file_processing.hpp"

/////////////////////////////CONSTRUCTOR AND DESTRUCTOR////////////////////////

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : value_btc_(other.value_btc_), amount_btc_(other.amount_btc_) {}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other)
{
  if (this != &other)
    *this = other;
  return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/////////////////////////////MEMBER FUNCTIONS//////////////////////////////////

void BitcoinExchange::print_btc_value_for_date(const std::string &input)
{
  if (can_open_file(input) == false || can_open_file("data.csv") == false)
  {
    std::cout << RED_ERROR << "File could't be opened\n";
    return ;
  }

  t_file_processing process;

  btc_value_get();

  process.file.open(input);
  if (file_empty(process.file, process.line) == true)
  {
    std::cout << RED_ERROR << "File " << input <<  " is empty\n";
    return ;
  }
  while(std::getline(process.file, process.line))
  {
    if (correct_line(process.line) == true)
    {
      split_date_and_value(process.line, process.separated_str);
      int_convert_date(process.separated_str[DATE], process.date_saved);
      float_convert_value(process.separated_str[VALUE],  process.value_saved);
      pair_save_next_line(process.date_saved, process.value_saved);
      find_corresponding_amount_to_value(process);
      multiply_values(process);
      print_corresponding_pair(process);
    }
    else if (value_line_check(process.line) == false)
      std::cout << RED_ERROR << "incorrect value " << process.line << std::endl;
    else
      std::cout << RED_ERROR << "bad input => " << process.line << std::endl;
  }
}

bool BitcoinExchange::can_open_file(const std::string &input)
{
  if (input.empty() == true)
    return (false);
  
  std::ifstream file;

  file.open(input);

  if (file.is_open() == false)
    return (false);

  file.close();
  return (true);
}

void BitcoinExchange::btc_value_get()
{
  std::ifstream file;
  std::string line;
  std::string separated_str[2];
  int date_saved;
  float value_saved;

  file.open("data.csv");
  if (file_empty(file, line) == true)
  {
    std::cout << RED_ERROR << "data.csv file is empty\n";
    return ;
  }
  while (std::getline(file, line))
  {
    if (correct_line(line) == true)
    {
      split_date_and_value(line, separated_str);
      int_convert_date(separated_str[DATE], date_saved);
      float_convert_value(separated_str[VALUE], value_saved);
      map_save_next_line(date_saved, value_saved);
    }
    else
      std::cout << RED_ERROR << "data.csv bad input => " << line << std::endl;
  }
  file.close();
}
/*
   std::cout << value_btc_.size() << std::endl;
   std::map<int, float>::iterator it;
   for (it = value_btc_.begin(); it != value_btc_.end(); ++it)
   std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
   */

bool BitcoinExchange::file_empty(std::ifstream &file, std::string &line) const
{
  std::getline(file, line);
  if (line.empty() == true)
    return (true);
  return (false);
}


bool BitcoinExchange::correct_line(const std::string &line) const
{
  if (line.size() < 12)
    return (false);
  else if (line.size() < 14 && line[10] != ',')
    return (false);
  else if (isdigit(line[line.size() - 1]) == false)
    return (false);
  else if (date_line_validation(line) == false)
    return (false);
  else if (value_line_check(line) == false)
    return (false);
  return (true);
}

bool BitcoinExchange::date_line_validation(const std::string &line) const
{
  std::string seperaded_line[2];

  split_date_and_value(line, seperaded_line);

  std::string date;

  date = seperaded_line[DATE];
  if (format_date_check(date) == false)
    return (false);

  int saved_date[3];

  array_date_convert(date, saved_date);
  if (is_date_within_limits(saved_date) == false)
    return false;
  return (true);
}

bool BitcoinExchange::format_date_check(const std::string &date) const
{
  if (date.size() != 10) //2011-01-00
   return (false);

  if (date[4] != '-' || date[7] != '-')
    return (false);

  if (isdigit(date[0]) == false || isdigit(date[1]) == false
      || isdigit(date[2]) == false || isdigit(date[3]) == false
      || isdigit(date[5]) == false || isdigit(date[6]) == false
      || isdigit(date[8]) == false || isdigit(date[9]) == false)
    return (false);
  return (true);
}

void BitcoinExchange::array_date_convert(const std::string &date,
                                   int saved_date[3]) const
{
  std::string cpy_of_input;

  cpy_of_input = date;
  cpy_of_input[4] = ' ';
  cpy_of_input[7] = ' ';

  std::istringstream convert(cpy_of_input);

  convert >> saved_date[YEAR] >> saved_date[MONTH] >> saved_date[DAY];
}

bool BitcoinExchange::is_date_within_limits(int saved_date[3]) const
{
  if (saved_date[YEAR] < 2008 || saved_date[YEAR] > 2022)
    return (false);
  else if (saved_date[MONTH] < 0 || saved_date[MONTH] > 12)
    return (false);
  else if (saved_date[DAY] < 0 || saved_date[DAY] > 31)
    return (false);
  else if (saved_date[MONTH] == 2 && saved_date[DAY] > 29)
    return (false);
  else if((saved_date[MONTH] == 4 || saved_date[MONTH] == 6 
            || saved_date[MONTH] == 9 || saved_date[MONTH] == 11)
            && saved_date[DAY] > 30)
    return (false);
  return (true);
}


void BitcoinExchange::split_date_and_value(const std::string &line,
                                         std::string separated_str[2]) const
{
  size_t sub_len = 10;

  separated_str[DATE] = line.substr(0, sub_len);

  if (line[10] == ',')
    sub_len = 11;
  else if (line.size() > 13)
    sub_len = 13;
  separated_str[VALUE] = line.substr(sub_len, (line.size() - 1));
}

bool BitcoinExchange::value_line_check(const std::string &line) const
{
  std::string seperaded_line[2];
  std::string value;

  split_date_and_value(line, seperaded_line);
  value = seperaded_line[VALUE];
  if (format_value_check(value) == false)
    return (false);
  else if (value_within_limits(value) == false)
    return (false);
  return (true);
}

bool BitcoinExchange::format_value_check(const std::string &value) const
{
  if (value[0] == '-')
    return (false);

  bool found_floating_point = false;
  for(int i = 0; value[i] != '\0'; i++)
  {
    if (i == 0 && value[i] == '+')
      i++;
    else if (value[i] == '.' && found_floating_point == false)
      i++;
    if(isdigit(value[i]) == false)
      return (false);
  }
  return (true);
}

bool BitcoinExchange::value_within_limits(const std::string &value) const
{
  std::istringstream convert;

  double check_value;
  convert.str(value);

  convert >> check_value;

  if (check_value > std::numeric_limits<float>::max())
    return (false);
  return (true);
}

bool BitcoinExchange::multiplied_number_limit_check(const std::string &line)
  std::string separated_line[2];
  int date_converted;
  float value_converted;
  float multiply_value;

  split_date_and_value(line, separated_line);
  int_convert_date(separated_line[DATE], date_converted);
  float_convert_value(separated_line[VALUE], value_converted);
  pair_save_next_line(date_converted, value_converted);
  find_corresponding_amount_to_value(multiply_value);

  if (value_converted * multiply_value > 1000)
    return (false);
  return (true);
}

void BitcoinExchange::int_convert_date(const std::string &date,
                                                int &saved_date) const
{
  std::string cpy_date;
  std::istringstream convert;

  cpy_date = date;
  cpy_date.erase(std::remove(cpy_date.begin(), cpy_date.end(), '-'),
                                                             cpy_date.end());
  convert.str(cpy_date);
  convert >> saved_date;
}

void BitcoinExchange::float_convert_value(const std::string &value,
                                                      float &value_saved)
{
  std::stringstream convert;

  convert.str(value);
  convert >> value_saved;

}

void BitcoinExchange::map_save_next_line(const int &date, const float &value)
{
  value_btc_.insert(std::map<int, float>::value_type(date, value));
}

void BitcoinExchange::pair_save_next_line(const int &date, const float &value)
{
  amount_btc_ = std::make_pair(date, value);
}

void BitcoinExchange::find_corresponding_amount_to_value(
                                                  t_file_processing &process)
{
  std::map<int, float>::const_iterator con_it;

  con_it = value_btc_.lower_bound(amount_btc_.first);
  process.multiply_value = con_it->second;
}

void BitcoinExchange::multiply_values(t_file_processing &process)
{
  process.value_to_print = process.multiply_value * amount_btc_.second;
}

void BitcoinExchange::print_corresponding_pair(
                                      const t_file_processing &process) const
{
  std::cout << process.separated_str[DATE]
    << " => "
    << amount_btc_.second
    << " = "
    << process.value_to_print
    << std::endl;
}
