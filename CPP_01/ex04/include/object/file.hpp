/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:23:43 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/29 18:34:00 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
class	File
{
	public:
				File(void);
		void	openFile(Input &input);
		void	readLineFromFile(Input &input);
	private:
		std::ofstream	_outFile;
		std::ifstream	_inFile;
		std::string		_fileLine;
};

#endif
