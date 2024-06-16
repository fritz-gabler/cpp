#ifndef  SCALAR_CONVERTER
#define  SCALAR_CONVERTER

#include <iostream>

class ScalarConverter
{
  public:

    //Methods
    static void convert(const std::string &);


  private:
    //Constructor and Destructors
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator = (const ScalarConverter &other);
    ~ScalarConverter();
    typedef enum e_type
    {
      CHAR = 0,
      INT = 1,
      FLOAT = 2,
      DOUBLE = 3,
      NOT_A_NUMBER = 4,
      NEG_INF = 5,
      POS_INF = 6,
      NOT_DEFINED = 7
    } t_type;

    void set_type(const std::string &);
    bool is_integer(const std::string &) const;
    bool is_float(const std::string &) const;
    bool is_double(const std::string &) const;
    t_type get_type() const;
    void convert_all_types(const std::string &);
    void char_convert(const std::string &);
    void convert_number(const std::string &);
    void not_a_number_convert();
    void infinity_convert();
    bool is_in_int_range(const std::string &) const;
    void print_converted_types() const;

    t_type       type_;
    int          int_converted_;
    char         char_converted_;
    float        float_converted_;
    double       double_converted_;
    std::string  error_message_[4];
};

#endif
