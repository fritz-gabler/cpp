#ifndef		PHONE_BOOK_OBJECT_H
#define		PHONE_BOOK_OBJECT_H

class	PhoneBook
{

	private	:
	Contact		Contact[8];

	public	:
	void	AddNewContact(int *LinesPrinted);
	void	GetFirstName(int *LinesPrinted);
};
#endif
