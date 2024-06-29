/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/29 19:08:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include "define.hpp"

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
      split_data_vale(line, seperated_str);
    }
    else
      std::cout << RED_ERROR << "Bad input => " << line << std::endl;
    std::getline(file, line);
  }
  file.close();
}

bool BitcoinExchange::correct_line(const std::string &line) const
{
  if (line.size() < 12)
    return (false);
  if (line.size() < 14 && line[10] != ',')
    return (false);
  if (isdigit(line[line.size() - 1]) == false)
    return (false);
  return (true);
}

void BitcoinExchange::split_data_vale(const std::string &line,
                                             std::string seperated_str[2])
{
  size_t sub_len = 10;

  seperated_str[0] = line.substr(0, sub_len);

  if (line[10] == ',')
    sub_len = 11;
  else if (line.size() > 13)
    sub_len = 13;
  seperated_str[1] = line.substr(sub_len, (line.size() - 1));
}
