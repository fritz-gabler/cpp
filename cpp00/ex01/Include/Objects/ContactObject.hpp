/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactObject.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:42:45 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 11:29:33 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef		CONTACT_OBJECT_H
# define		CONTACT_OBJECT_H

#include "PhoneBook.hpp"

////////////////////////////////////CLASS///////////////////////////////////////

class	Contact
{
	private	:
	std::string		FirstName;
	std::string		LastName;
	std::string		NickName;
	std::string		PhoneNumber;
	std::string		DarkestSecret;

	public	:
	void	AddFirstName(std::string Input);
	void	AddLastName(std::string Input);
	void	NickNameAdd(std::string Input);
	void	PhoneNumberAdd(std::string Input);
	void	AddDarkestSecret(std::string Input);
	void	DisplayContact(int ContactNumber);
	void	print();
};

#endif

