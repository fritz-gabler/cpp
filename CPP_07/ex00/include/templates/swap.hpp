#ifndef SWAP_HPP
#define SWAP_HPP

template<typename Template>
void swap(Template &one, Template &two)
{
  Template tmp;

  tmp = one;
  one = two;
  two = tmp;
}

#endif
