#ifndef  SCALAR_CONVERTER
#define  SCALAR_CONVERTER

#include <iostream>

class ScalarConverter
{
  public:
    //Constructor and Destructors
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator = (const ScalarConverter &other);
    ~ScalarConverter();

    //Methods
    static void convert(const std::string &);


  private:
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
    } s_type;

    void set_type_due_to_first_char(const std::string &);
    bool class_input_check(const std::string &) const;
    bool is_special_number_sigh(const std::string &) const;
    bool mixed_input(const std::string &) const ;
    bool is_char_in_str(const std::string &) const;
    bool is_number_in_str(const std::string &) const;
    bool wrong_signs(const std::string &) const ;
    bool just_valid_numbers(const std::string &) const;
    bool just_valid_chars(const std::string &) const;
    void convert_all_types(const std::string &);
    void char_convert(const std::string &);
    bool is_in_int_range(const std::string &) const;
    bool is_printable(const std::string &) const;
    bool is_ascii(const std::string &) const;
    void int_convert(const std::string &);
    void float_convert(const std::string &);
    void double_convert(const std::string &);
    void print_converted_types() const;

    s_type       type_;
    char         char_converted_;
    int          int_converted_;
    float        float_converted_;
    double       double_converted_;
    std::string  error_message_[4];
};

#endif
