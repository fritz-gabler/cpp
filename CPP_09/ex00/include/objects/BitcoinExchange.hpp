#ifndef BITCOUN_EXCHANGE_HPP
#define BITCOUN_EXCHANGE_HPP

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
    void array_date_convert(const std::string &date, int saved_date[3]) const;
    bool is_date_within_limits(int saved_date[3]) const;
    void split_date_and_value(const std::string &line,
                                std::string seperated_str[2]) const;
    void int_convert_date(const std::string &date, int &saved_date) const;
    void map_save_next_line(std::string seperated_str[2]);
    void pair_save_next_line(std::string seperated_str[2]);
    void pair_check() const;
    void find_corresponding_amount_to_value();
    void print_corresponding_pair();

    enum e_date
    {
      YEAR = 0,
      MONTH = 1,
      DAY = 2
    };

    std::map<int, float> btc_value_;
    std::pair<int, float> btc_amount_;
};

#endif
