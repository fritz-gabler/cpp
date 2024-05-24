#ifndef MIN_HPP
#define  MIN_HPP

template<typename Template>
Template min(Template one, Template two)
{
  if (one < two)
    return (one);
  else if (two < one)
    return (two);
  return (two);
}

#endif
