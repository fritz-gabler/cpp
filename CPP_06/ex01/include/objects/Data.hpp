#ifndef DATA_HPP
#define DATA_HPP

class Data
{
  public:
    Data();
    Data(const Data &other);
//    Data &operator = (const Data &);
    ~Data();

    //Member function
    void print_this_ptr() const;
    void print_a_fun_number() const;
  private:
    int a_fun_number;
};

#endif
