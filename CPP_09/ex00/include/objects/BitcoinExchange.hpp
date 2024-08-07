#ifndef BITCOUN_EXCHANGE_HPP
#define BITCOUN_EXCHANGE_HPP

#include <string>
#include <map>
#include "file_processing.hpp"

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
    void process_input_lines(const std::string &input);
    bool file_empty(const std::string &input) const;
    bool is_file_header(std::ifstream &file);
    bool correct_line(const std::string &line);
    bool just_valid_characters(const std::string &line) const;
    bool valid_character(const char c) const;
    bool date_line_validation(const std::string &line) const;
    bool format_date_check(const std::string &date) const;
    void array_date_convert(const std::string &date, int saved_date[3]) const;
    bool is_date_within_limits(int saved_date[3]) const;
    void split_date_and_value(const std::string &line,
                                std::string separated_str[2]) const;
    bool value_line_check(const std::string &line) const;
    bool format_value_check(const std::string &value) const;
    bool value_within_limits(const std::string &value) const;
    bool multiplied_number_limit_check(const std::string &line);
    bool input_smaller_one_thousand(const std::string line);
    void int_convert_date(const std::string &date, int &saved_date);
    void float_convert_value(const std::string &value, float &value_saved);
    void map_save_next_line(const int &date, const float &value);
    void pair_save_next_line(const int &date, const float &value);
    void find_corresponding_amount_to_value(float &multiply_value);
    void multiply_values(t_file_processing &process);
    void print_corresponding_pair(const t_file_processing &process) const;

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

    std::map<int, float> value_btc_;
    std::pair<int, float> amount_btc_;
};

#endif
