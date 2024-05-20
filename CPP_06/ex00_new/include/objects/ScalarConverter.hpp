#ifndef  SCALAR_CONVERTER
#define  SCALAR_CONVERTER

#include <iostream>

class ScalarConverter
{
  public:
    //Constructor and Destructors
    ScalarConverter(void);
    ScalarConverter(const std::string &input);
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator = (const ScalarConverter &other);
    ~ScalarConverter(void);

    //Methods
    static void convert(const std::string &);

  private:
    //Input check
    bool class_input_check(const std::string &) const;
    bool mixed_input(const std::string &) const ;
    bool is_char_in_str(const std::string &) const;
    bool is_number_in_str(const std::string &) const;
    bool wrong_signs(const std::string &) const ;

    std::string  input_;
    char         char_converted_;
    int          int_converted_;
    float        float_converted_;
    double       double_converted_;
};

#endif
