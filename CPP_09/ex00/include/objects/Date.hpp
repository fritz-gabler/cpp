#ifndef DATE
#define DATE

#include <string>
#define FOUND 0

class Date
{
  public:
    Date();
    Date(const Date &other);
    Date &operator = (const Date &other);
    bool operator<(const Date &other) const;
    ~Date();

    void set_date(const std::string &date);
    void print_date() const;
  private:
    bool valid_date_format_check(const std::string &) const;
    void convert_date_string_to_date_int(const std::string &);
    bool validate_date_check() const;

    enum e_date
    {
      YEAR = 0,
      MONTH = 1,
      DAY = 2
    };
    int date_[3];
};

#endif
