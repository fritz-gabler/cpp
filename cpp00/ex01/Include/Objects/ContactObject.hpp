/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactObject.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:42:45 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 12:29:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef		CONTACT_OBJECT_H
# define		CONTACT_OBJECT_H

#include "PhoneBook.hpp"

////////////////////////////////////CLASS///////////////////////////////////////

class	Contact
{
	private	:
	std::string		firstName;
	std::string		lastName;
	std::string		nickName;
	std::string		phoneNumber;
	std::string		darkestSecret;

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

