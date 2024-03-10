/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:42:45 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 12:00:12 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef		CONTACT_HPP
# define		CONTACT_HPP

#include "Header.hpp"

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
		void	DisplayContactSnippet(int ContactNumber);
		void	DisplayAllConatctData(void);
};

#endif

