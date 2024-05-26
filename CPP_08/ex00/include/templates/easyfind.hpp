#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
bool easyfind(T &object, int number_to_find)
{
  if (std::find(object.begin(), object.end(), number_to_find) == object.end())
    return false;
  return (true);
}

#endif
