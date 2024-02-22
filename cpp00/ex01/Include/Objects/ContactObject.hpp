# ifndef		CONTACT_OBJECT_H
# define		CONTACT_OBJECT_H


////////////////////////////////////CLASS///////////////////////////////////////

class	Contact
{
	private	:
	int				id;
	std::string		FirstName;
	std::string		LastName;
	std::string		BirthDate;
	std::string		DarkestSecret;

	public	:
	Contact(void);
	void	AddFirstName();
	void	AddDarkestSecret(void);
	void	AddBirthDate(void);
	void	AddLastName(void);



};

////////////////////////////////////METHODS//////////////////////////////////-//


#endif

