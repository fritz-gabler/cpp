#ifndef ARRAY_HPP
#define ARRAY_HPP

//INCLUDES
#include <iostream>

template<typename T>
class Array
{
  private:
    T      *array_;
    int    size_;

  public:
    Array(){
      array_ = NULL;
      size_ = 0;
    }
    Array(size_t array_size) : size_(array_size) {
      array_ = new T[array_size];
    }
    Array(const Array &other) {
      array_ = NULL;
      *this = other;
    };
    Array &operator = (const Array &other)
    {
      if (this == &other)
        return (*this);

      if (array_ != NULL) {
        delete [] array_;
        array_ = NULL;
      }
      array_ = new T[other.size_];
      size_ = other.size_;
      for (int i = 0; i < size_; i++) {
        array_[i] = other.array_[i];
      }
      return (*this);
    }
    ~Array() {
      if (array_ != NULL)
        delete [] array_;
    }

    size_t size() const {
      return (size_);
    }
    
    T &operator[](int intdex) {
      if (intdex >= 0 && intdex < size_)
        return (array_[intdex]);
      else
        throw out_of_range_exception();
    }

    class out_of_range_exception : public std::exception {
      public:
        virtual const char *what() const throw() {
          return ("Out of array range");
        };
    };

};
#endif
