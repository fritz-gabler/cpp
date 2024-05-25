#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename Ptr_to_array>
void iter(Ptr_to_array *ptr, size_t size,  void(*function)(Ptr_to_array))
{
  if (ptr == NULL || size < 1 || function == NULL)
    return ;
  for(size_t i = 0; i < size; i++)
  {
    function(ptr[i]);
  }
}

#endif