/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/01 09:24:38 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include "define.hpp"
#include "sstream"

/////////////////////////////CONSTRUCTOR AND DESTRUCTOR////////////////////////

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : btc_value(other.btc_value), btc_amount(other.btc_amount) {}

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
  if (can_open_file(input) == false)
  {
    std::cout << RED_ERROR << "File data.csv could't be opend\n";
    return ;
  }
  btc_value_get();
}

bool BitcoinExchange::can_open_file(const std::string &input)
{
  if (input.empty() == true)
    return (false);
  
  std::ifstream file;

  file.open("data.csv");

  if (file.is_open() == false)
    return (false);

  file.close();
  return (true);
}

void BitcoinExchange::btc_value_get()
{
  std::ifstream file;
  std::string line;
  std::string seperated_str[2];


  file.open("data.csv");

  std::getline(file, line);
  if (line.empty() == true)
  {
    std::cout << RED_ERROR << "data.csv file is empty\n";
    return ;
  }

  std::getline(file, line);
  while (line.empty() == false)
  {
    if (correct_line(line) == true)
    {
      split_date_and_value(line, seperated_str);
      map_save_next_line(seperated_str);
    }
    else
      std::cout << RED_ERROR << "data.csv bad input => " << line << std::endl;
    std::getline(file, line);
  }
/*
  for (std::map<Date, float>::iterator it = btc_value.begin(); it != btc_value.end(); ++it)
  {
    std::cout << "Key: ";
    it->first.print_date();
    std::cout << ", Value: " << it->second << std::endl;
  }
*/
  file.close();
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

  date_convert(date, saved_date);

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

void BitcoinExchange::date_convert(const std::string &date,
                                   int saved_date[3]) const
{
  std::string cpy_of_input;
  std::istringstream convert(cpy_of_input);

  cpy_of_input = date;
  cpy_of_input[4] = ' ';
  cpy_of_input[7] = ' ';
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
                                         std::string seperated_str[2]) const
{
  size_t sub_len = 10;

  seperated_str[0] = line.substr(0, sub_len);

  if (line[10] == ',')
    sub_len = 11;
  else if (line.size() > 13)
    sub_len = 13;
  seperated_str[1] = line.substr(sub_len, (line.size() - 1));
}

void BitcoinExchange::map_save_next_line(std::string seperated_str[2])
{
  int date;
  float value_add;
  std::istringstream convert(seperated_str[0]);

  convert >> date;
  convert.clear();
  convert.str(seperated_str[0]);
  convert >> value_add;
  btc_value.insert(std::make_pair(date, value_add));
}

void BitcoinExchange::pair_save_next_line(std::string seperated_str[2])
{
  int date;
  float value_add;
  std::istringstream convert(seperated_str[0]);

  convert >> date;
  convert.clear();
  convert.str(seperated_str[0]);
  convert >> value_add;
  btc_amount = std::make_pair(date, value_add);
}
