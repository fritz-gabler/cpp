#ifndef		STRUCTURES_H
#define		STRUCTURES_H

////////////////////////////////////INCLUDE////////////////////////////////////////

#include "Header.hpp"

////////////////////////////////////ENUM////////////////////////////////////////

typedef enum	EStatus
{
	Add				=	0,
	Search			=	1,
	Exit			=	2,
	FalseInput		=	3,
	Start			=	4,
	ColseContact	=	5,
	NoContact		=	6
}	TStatus;

////////////////////////////////////STRUCT//////////////////////////////////////

typedef struct	s_Process
{
	std::string			Input;
	int					Status;
	int					PrintedLines;
} Process;

#endif
