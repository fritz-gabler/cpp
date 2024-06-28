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
    ~Date();

    void set_date(const std::string &date);
  private:
    bool valid_date_format_check(const std::string &) const;
    void convert_date_string_to_date_int();
    bool validate_date();
    std::string &get_date() const;

    enum
    {
      YEAR = 0,
      MONTH = 1,
      DAY = 2
    };
    int date_[3];
};

#endif
