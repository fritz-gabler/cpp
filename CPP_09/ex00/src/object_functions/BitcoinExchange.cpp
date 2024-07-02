/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/02 14:02:57 by fgabler          ###   ########.fr       */
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
    : btc_value_(other.btc_value_), btc_amount_(other.btc_amount_) {}

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
  if (file_empty(process.file, process.line) == false);
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
      float_convert_value(process.separated_str[DATE],  process.value_saved);
      pair_save_next_line(process.date_saved, process.value_saved);
      
    }
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
   std::cout << btc_value_.size() << std::endl;
   std::map<int, float>::iterator it;
   for (it = btc_value_.begin(); it != btc_value_.end(); ++it)
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

  std::string seperaded_line[2];
  
  split_date_and_value(line, seperaded_line);

  if (date_validation(seperaded_line[0]) == false)
    return (false);
  return (true);
}

bool BitcoinExchange::date_validation(std::string &date) const
{
  int saved_date[3];

  if (format_check(date) == false)
    return (false);

  array_date_convert(date, saved_date);

  if (is_date_within_limits(saved_date) == false)
    return false;
  return (true);
}

bool BitcoinExchange::format_check(const std::string &date) const
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
  btc_value_.insert(std::map<int, float>::value_type(date, value));
}

void BitcoinExchange::pair_save_next_line(const int &date, const float &value)
{
  btc_amount_ = std::make_pair(date, value);
}
