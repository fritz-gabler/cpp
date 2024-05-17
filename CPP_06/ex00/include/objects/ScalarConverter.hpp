#ifndef  SCALAR_CONVERTER
#define  SCALAR_CONVERTER

#include <iostream>

class ScalarConverter
{
  public:
    //Constructor and Destructors
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator = (const ScalarConverter &other);
    ~ScalarConverter(void);

    //Methods

    static void convert(const std::string &);
    static void char_print_if_possible(const std::string &);
    static void int_print_if_possible(const std::string &);
    static void float_print_if_possible(const std::string &);
    static void double_print_if_possible(const std::string &);

    //Input check
    static bool is_valide_char(const std::string &);
    static bool is_special_double_value(const std::string &);
    static bool is_special_float_value(const std::string &);
    static bool is_negative_infinity(const std::string &);
};

#endif
