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
	std::string		FavoriteAnimal;

	public	:
	Contact();
	void	AddFirstName();
};

////////////////////////////////////METHODS//////////////////////////////////-//

Contact::Contact(void)
{
	id = 0;
}

void	Contact::AddFirstName()
{
	 FirstName = "hallo";
}
#endif

