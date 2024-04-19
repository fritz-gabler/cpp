/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:34:13 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/18 19:36:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void	littleCatCopyTest( void );
static void	littleDogCopyTest( void );

void	copyTest( void )
{
	std::cout << "\n------------------COPY TEST------------------\n";
	littleCatCopyTest();
	littleDogCopyTest();
}

static void	littleCatCopyTest( void )
{
	Cat	littleCat;
	Cat	copyOfLittleCat;

	littleCat.saveNewIdea("orginal little Cat Idea");
	copyOfLittleCat = littleCat;
	std::cout << std::endl;
	copyOfLittleCat.changeAnIdea("i wana memorize someting my self", 0);
	std::cout << "Little Cat: ";
	littleCat.printAnSpecificIdea(0);
	std::cout << "Copy little Cat: ";
	copyOfLittleCat.printAnSpecificIdea(0);
	std::cout << std::endl;
}

static void	littleDogCopyTest( void )
{
	Dog	littleDog;
	Dog	copyOfLittleDog;


	littleDog.saveNewIdea("A secret Dog thought");
	copyOfLittleDog = littleDog;
	std::cout << std::endl;
	copyOfLittleDog.changeAnIdea("i wana memorize someting my self", 0);
	std::cout << "Little Dog: ";
	littleDog.printAnSpecificIdea(0);
	std::cout << "Copy little Dog: ";
	copyOfLittleDog.printAnSpecificIdea(0);
	std::cout << std::endl;
}
