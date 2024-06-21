#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <iterator>
#include <deque>
#include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
  public:
    MutantStack() : std::stack<T, Container>() {};
    MutantStack(const MutantStack &other) : std::stack<T, Container>(other){};
    MutantStack &operator = (const MutantStack &other)
    {
      std::stack<T, Container>::operator=(other);
      return (*this);
    }

    typedef typename Container::iterator iterator;
    typedef typename  Container::const_iterator const_iterator;
    typedef typename  Container::reverse_iterator reverse_iterator;
    typedef typename  Container::const_reverse_iterator const_reverse_iterator;

    iterator begin()
    {
      return (this->c.begin());
    }
    
    iterator end()
    {
      return (this->c.end());
    }

    const_iterator begin() const
    {
      return (this->c.begin());
    }

    const_iterator end() const
    {
      return (this->c.end());
    }

    reverse_iterator rbegin()
    {
      return (this->c.rbegin());
    }

    reverse_iterator rend()
    {
      return (this->rend());
    }

    const_reverse_iterator rbegin() const
    {
      return (this->c.rbegin());
    }

    const_reverse_iterator rend() const
    {
      return (this->rend());
    }
};

template <typename T, typename Container>
std::ostream &operator << (std::ostream &ostream, const MutantStack<T, Container>& mutant_stack)
{
  typename MutantStack<T, Container>::const_reverse_iterator rit;

  for (rit = mutant_stack.rbegin(); rit != mutant_stack.rend(); rit++)
    ostream << *rit << std::endl;

  return (ostream);
}

#endif
