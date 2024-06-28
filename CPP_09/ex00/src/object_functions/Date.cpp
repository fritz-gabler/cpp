/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:04:55 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/28 16:51:44 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <cctype>
#include <iostream>
#include <sstream>

/////////////////////////////CONSTRUCTOR AND DESTRUCTOR////////////////////////

Date::Date()
{
  date_[YEAR] = 0;
  date_[MONTH] = 0;
  date_[DAY] = 0;
}

Date::Date(const Date &other)
{
  date_[YEAR] = other.date_[YEAR];
  date_[MONTH] = other.date_[MONTH];
  date_[DAY] = other.date_[DAY];
}

Date &Date::operator = (const Date &other)
{
  if (this != &other)
    *this = other;
  return (*this);
}

Date::~Date() {}

/////////////////////////////MEMBER FUNCTIONS//////////////////////////////////

void Date::set_date(const std::string &date)
{
  if (valid_date_format_check(date) == false)
    std::cout << "Date is in invalid format\n";

  convert_date_string_to_date_int(date);
}

bool Date::valid_date_format_check(const std::string &input) const
{
  if (input.size() != 10) //2011-01-00
    return (false);

  if (input[4] != '-' || input[7] != '-')
    return (false);

  if (isalpha(input[0]) != FOUND || isalpha(input[1]) != FOUND
      || isalpha(input[2]) != FOUND || isalpha(input[3]) != FOUND
      || isalpha(input[5]) != FOUND || isalpha(input[6]) != FOUND
      || isalpha(input[8]) != FOUND || isalpha(input[9]) != FOUND)
    return (false);

  return (true);
}

void Date::convert_date_string_to_date_int(const std::string &date)
{
  std::string cpy_of_input = date;
  cpy_of_input[4] = ' ';
  cpy_of_input[7] = ' ';

  std::stringstream convert(cpy_of_input);
  
  convert >> date_[YEAR] >> date_[MONTH] >> date_[DAY];
}

bool validate_date_check() const
{
  if (date_[YEAR])
  return (true);
}
