#ifndef		PHONEBOOK_HPP
#define		PHONEBOOK_HPP

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////INCLUDES/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "Header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////CLASSES////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class	PhoneBook
{

	private	:
	int			indexOfContact;
	int			numberOfContacts;
	Contact		contact[8];

	public	:
	PhoneBook(void);
	void	AddNewContact(Process &process);
	void	GetFirstName(Process &process);
	void	GetLastName(Process &process);
	void	GetNickName(Process &process);
	void	GetPhoneNumber(Process &process);
	void	GetDarkestSecret(Process &process);
	void	SearchContact(Process &process);
	void	DisplayContactSnippet(Process &process);
	void	DisplaySpecificContact(Process &process);
	void	GetValidContactNumber(int &Number, Process &process);
	void	SetNumber(void);
	void	ResetNumber(void);
	bool	ContactExist();
};

#endif
