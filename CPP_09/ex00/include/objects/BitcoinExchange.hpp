#ifndef BITCOUN_EXCHANGE_HPP
#define BITCOUN_EXCHANGE_HPP

#include "Date.hpp"
#include <string>
#include <map>

class BitcoinExchange
{
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator = (const BitcoinExchange &other);
    ~BitcoinExchange();

    void print_btc_value_for_date(const std::string &input);

  private:
    bool can_open_file(const std::string &input);
    void btc_value_get();
    void save_next_line(std::string &input);
    void pair_check() const;
    void find_corresponding_amount_to_value();
    void print_corresponding_pair();



    std::map<Date, float> btc_value;
    std::pair<Date, float> btc_amount;
};

#endif
