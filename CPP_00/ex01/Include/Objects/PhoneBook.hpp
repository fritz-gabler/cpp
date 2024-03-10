#ifndef		PHONEBOOK_HPP
#define		PHONEBOOK_HPP

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////INCLUDES/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "Header.hpp"
#include "Contact.hpp"

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
	void	AddNewContact(int *LinesPrinted);
	void	GetFirstName(int *LinesPrinted);
	void	GetLastName(int *LinesPrinted);
	void	GetNickName(int *LinesPrinted);
	void	GetPhoneNumber(int *LinesPrinted);
	void	GetDarkestSecret(int *LinesPrinted);
	void	SearchContact(int &linesPrinted);
	void	DisplayContactSnippet(int &linesPrinted);
	void	DisplaySpecificContact(int &linesPrinted);
	void	GetValidContactNumber(int &Number, int &LinesPrinted);
	void	SetNumber(void);
	void	ResetNumber(void);
	bool	ContactExist();
};

#endif
