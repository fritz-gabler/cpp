#ifndef		PHONE_BOOK_OBJECT_H
#define		PHONE_BOOK_OBJECT_H

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
	void	DisplayContactSnipet(int &linesPrinted);
	void	DisplaySpecificContact(int &linesPrinted);
	void	GetValideContactNumber(int &Number, int &LinesPrinted);
	void	SetNumber(void);
	void	ResetNumber(void);
	bool	ContactExist();
};

#endif
