# ifndef		CONTACT_OBJECT_H
# define		CONTACT_OBJECT_H


////////////////////////////////////CLASS///////////////////////////////////////

#include <string>
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
	void	AddFirstName(std::string Input);
	void	AddDarkestSecret(std::string Input);
	void	AddBirthDate(std::string Input);
	void	AddLastName(std::string Input);
};

////////////////////////////////////METHODS//////////////////////////////////-//


#endif

