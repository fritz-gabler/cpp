#ifndef		PHONE_BOOK_OBJECT_H
#define		PHONE_BOOK_OBJECT_H

class	PhoneBook
{

	private	:
	int			numberOfContacts;
	Contact		contact[8];

	public	:
	PhoneBook(void);
	void	AddNewContact(int *LinesPrinted);
	void	SetContactNumber(void);
	void	GetFirstName(int *LinesPrinted);
	void	GetLastName(int *LinesPrinted);
	void	GetNickName(int *LinesPrinted);
	void	GetPhoneNumber(int *LinesPrinted);
	void	GetDarkestSecret(int *LinesPrinted);
	void	SearchContact(int *LinesPrinted);
	bool	ContactExist();
	void	print(void);
};

#endif
