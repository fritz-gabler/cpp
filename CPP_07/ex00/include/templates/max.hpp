#ifndef MAX_HPP
#define MAX_HPP

template<typename Template>
Template max(Template one, Template two)
{
  if (one > two)
    return (one);
  else if (two > one)
    return (two);
  return(two);
}

#endif
