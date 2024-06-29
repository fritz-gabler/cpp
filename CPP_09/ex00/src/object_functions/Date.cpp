/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:04:55 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/29 12:28:48 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include "colors.hpp"
#include "define.hpp"

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

bool Date::operator < (const Date &other) const
{
  if (date_[YEAR] != other.date_[YEAR])
    return date_[YEAR] < other.date_[YEAR];
  else if (date_[MONTH] != other.date_[MONTH])
    return date_[MONTH] < other.date_[MONTH];
  else
    return date_[DAY] < other.date_[DAY];
}


Date::~Date() {}

/////////////////////////////MEMBER FUNCTIONS//////////////////////////////////

void Date::set_date(const std::string &date)
{
  if (valid_date_format_check(date) == false)
    std::cout << "Date is in invalid format\n";

  convert_date_string_to_date_int(date);

  if (validate_date_check() == false)
    std::cout << RED_ERROR << YEAR_ERROR << date_[YEAR] << "\n";
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

  std::istringstream convert(cpy_of_input);
  
  convert >> date_[YEAR] >> date_[MONTH] >> date_[DAY];
}

bool Date::validate_date_check() const
{
  if (date_[YEAR] < 2008 || date_[YEAR] > 2022)
    return (false);
  else if (date_[MONTH] < 0 || date_[MONTH] > 12)
    return (false);
  else if (date_[DAY] < 0 || date_[DAY] > 31)
    return (false);
  else if ((date_[MONTH] == 2 && date_[DAY] > 29)
            || (date_[MONTH] == 4 && date_[DAY] > 30)
            || (date_[MONTH] == 6 && date_[DAY] > 30)
            || (date_[MONTH] == 9 && date_[DAY] > 30)
            || (date_[MONTH] == 11 && date_[DAY] > 30))
    return (false);
  return (true);
}

void Date::print_date() const
{
  if (date_[YEAR] == 0 || date_[MONTH] == 0 || date_[DAY] == 0)
    return ;
  std::cout << date_[YEAR] << "-" << date_[MONTH] << date_[DAY];
}
