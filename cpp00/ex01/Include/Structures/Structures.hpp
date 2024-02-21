#ifndef		STRUCTURES_H
#define		STRUCTURES_H

////////////////////////////////////ENUM////////////////////////////////////////

typedef enum	EStatus
{
	Add			=	0,
	Search		=	1,
	Exit		=	2,
	FalseInput	=	3,
	Start		=	4
}	TStatus;

////////////////////////////////////STRUCT//////////////////////////////////////

typedef struct	s_Process
{
	std::string		Input;
	int				Status;
} Process;

#endif
