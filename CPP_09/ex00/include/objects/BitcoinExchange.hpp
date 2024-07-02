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
    bool file_empty(std::ifstream &file, std::string &line) const;
    bool correct_line(const std::string &line) const;
    bool date_line_validation(const std::string &line) const;
    bool format_date_check(const std::string &date) const;
    void array_date_convert(const std::string &date, int saved_date[3]) const;
    bool is_date_within_limits(int saved_date[3]) const;
    void split_date_and_value(const std::string &line,
                                std::string separated_str[2]) const;
    bool value_line_check(const std::string &line) const;
    bool format_value_check(const std::string &value) const;
    bool value_within_limits(const std::string &value) const;
    void int_convert_date(const std::string &date, int &saved_date) const;
    void float_convert_value(const std::string &value, float &value_saved);
    void map_save_next_line(const int &date, const float &value);
    void pair_save_next_line(const int &date, const float &value);

    void pair_check() const;
    void find_corresponding_amount_to_value();
    void print_corresponding_pair();

    enum e_date
    {
      YEAR = 0,
      MONTH = 1,
      DAY = 2
    };

    enum e_separate
    {
      DATE = 0,
      VALUE = 1
    };

    std::map<int, float> btc_value_;
    std::pair<int, float> btc_amount_;
};

#endif
