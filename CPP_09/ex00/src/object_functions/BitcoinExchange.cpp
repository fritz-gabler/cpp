/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/29 15:22:13 by fgabler          ###   ########.fr       */
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

  while (line.empty() == false)
  {
    
  }
}

bool correct_line(const std::string &line) const
{
  if (line.size() < 14)
    return (false);
  if (line.size() < 12)
    return (false);
  if (line[10] != ' ' || line[11] != '|')
    return (false);
  return (true);
}

void BitcoinExchange::split_data_vale(const std::string &line,
                                             std::string seperated_str[2]);
{
  
}


