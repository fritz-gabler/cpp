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
    bool correct_line(const std::string &line) const;
    bool date_validation(std::string &date) const;
    bool format_check(const std::string &date) const;
    void date_convert(const std::string &date, int saved_date[3]);
    bool is_date_within_limits(int saved_date[3]) const;
    void split_data_vale(const std::string &line, std::string seperated_str[2]);
    void map_save_next_line(std::string seperated_str[2]);
    void pair_save_next_line(std::string seperated_str[2]);
    void pair_check() const;
    void find_corresponding_amount_to_value();
    void print_corresponding_pair();


    std::map<Date, float> btc_value;
    std::pair<Date, float> btc_amount;
};

#endif
