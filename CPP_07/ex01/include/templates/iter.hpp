#ifndef ITER_HPP
#define ITER_HPP

template<typename Ptr_to_array, typename Array_size, typename Function>
void iter(Ptr_to_array *ptr, Array_size size, Function function)
{
  if (ptr == NULL || size < 1 || function == NULL)
    return ;
  for(int i = 0; i < size; i++)
  {
    function(ptr[i]);
  }
}

#endif
