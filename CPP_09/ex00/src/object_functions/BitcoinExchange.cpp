/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/29 13:25:01 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

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
    std::cout << 
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
