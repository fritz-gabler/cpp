/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_with_level.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:08 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/09 14:26:35 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void print_color(int level);

void print_message_with_level(std::string message, int level) {
  print_color(level);
  std::cout << message << std::endl;
}

static void print_color(int level) {
  switch (level) {
  case TEST:
    std::cout << BLUE << "[TEST] " << RESET;
    break;
  case WARNING:
    std::cout << YELLOW << "[WARNING] " << RESET;
    break;
  case ERROR:
    std::cout << RED << "[ERROR] " << RESET;
  case NOTE:
    std::cout << DARK_GREEN << "[NOTE] " << RESET;
    break;
  }
}
