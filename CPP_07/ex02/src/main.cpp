/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:59:54 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/25 15:41:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "define.hpp"
#include "header.hpp"

int main() {
  log("Fist let's run the subject test\n", TEST);
  subject_test();
  std::cout << "\n";
  log("And now let's run the selfe created test\n", TEST);
  selfe_created_test();
  return (0);
}
