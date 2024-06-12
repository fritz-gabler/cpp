#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdio>
#include "Data.hpp"

typedef unsigned long long my_uintptr_t;

class Serializer
{
  public:

    static my_uintptr_t serialize(Data* ptr);
    static Data *deserialize(my_uintptr_t raw);

  private:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator = (const Serializer &);
    ~Serializer();
};

#endif
