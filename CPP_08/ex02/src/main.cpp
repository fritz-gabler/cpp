/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:28:20 by fgabler           #+#    #+#             */
/*   Updated: 2024/06/20 16:25:54 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include "header.hpp"

static void pdf_test();
static void check_with_other_type();

int main()
{
  std::cout << "\n";
  pdf_test();
  std::cout << "\n";
  check_with_other_type();
}

static void pdf_test()
{
  log("PDF TEST WITH MUTANT STACK CLASS\n", TEST);
  MutantStack<int> mstack;

  log("ADD 10 ELEMENTS FROM 0 - 9\n", NOTE);
  for (int i = 0; i < 10; i++)
    mstack.push(i);

  log("NOW LETS VIEW TOP:", NOTE);
  std::cout << mstack.top() << "\n\n";

  log("NOW LETS POP ONE ELEMENT", NOTE);
  mstack.pop();
  std::cout << mstack.top() << "\n\n";

  log("SIZE:", NOTE);
  std::cout << mstack.size() << "\n\n";


  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;


  log("LETS PRINT OUT THE WHOLE STACK:", NOTE);
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}


static void check_with_other_type()
{
  log("PDF TEST WITH LIST TO CHECK\n", TEST);

  std::list<int> list;

  log("ADD 10 ELEMENTS FROM 0 - 9\n", NOTE);
  for (int i = 0; i < 10; i++)
    list.push_back(i);

  log("NOW LETS VIEW TOP:", NOTE);
  std::cout << list.back() << "\n\n";

  log("NOW LETS POP ONE ELEMENT", NOTE);
  list.pop_back();
  std::cout << list.back() << "\n\n";

  log("SIZE:", NOTE);
  std::cout << list.size() << "\n\n";


  std::list<int>::iterator it = list.begin();
  std::list<int>::iterator ite = list.end();

  ++it;
  --it;


  log("LETS PRINT OUT THE WHOLE STACK:", NOTE);
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
}
