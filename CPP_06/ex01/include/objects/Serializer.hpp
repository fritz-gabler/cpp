#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdio>
#include "Data.hpp"

typedef unsigned long long uintptr_t;

class Serializer
{
  public:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator = (const Serializer &);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif
