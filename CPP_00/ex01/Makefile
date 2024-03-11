
NAME			=		PhoneBook

###############################################################################
###############################################################################

CC				=		c++
CFLAGS			=		-Wall -Werror -Wextra
CPPFLAG			=		-std=c++98
HEADERS			=		-I./Include -I./Include/Objects -I./Include/Structures

###############################################################################
###############################################################################

VPATH			:=		Src Src/DisplayPromt Src/ObjectMethods				\
						Src/InputParsing Src/ProcessFunctions				\
						Src/SearchContact

SRC_BOOK		=		main.cpp
SRC_PROMPT		=		HeaderPrint.cpp ResetPrompt.cpp 
SRC_METHODS		=		PhoneBook.cpp Contact.cpp
SRC_PARSING		=		GetCommand.cpp IsString.cpp SetAction.cpp			\
						ValidPhoneNumber.cpp
SRC_PROCESS		=		ResetProcess.cpp SetProcess.cpp
SRC_SEARCH		=		WaitTillInput.cpp DisplayContactSnippet.cpp			\
						isValidContactNumber.cpp convertStringToInt.cpp
SRC				=		$(SRC_BOOK) $(SRC_PROMPT) $(SRC_METHODS)			\
						$(SRC_PARSING) $(SRC_PROCESS) $(SRC_SEARCH)

###############################################################################
###############################################################################

OBJ_DIR			:=		./_obj
OBJ				:=		$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

###############################################################################
###############################################################################

all:		$(NAME)

$(NAME):	$(LIBS_NAME) $(OBJ)
	@echo	$(YELLOW)Compiling [$(NAME)]...$(RESET)
	@printf $(UP)$(CUT)
	@$(CC)	$(CFLAGS) $(OBJ) -o $(NAME)
	@echo	$(GREEN)Success [$(NAME)] is compiled$(RESET)

$(OBJ_DIR)/%.o: %.cpp
	@echo $(YELLOW)Compiling [$@]...$(RESET)
	@printf $(UP)$(CUT)
	@if	[ ! -d "{OBJ_DIR}" ]; then						\
		mkdir -p _obj;									\
	fi
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

###############################################################################
###############################################################################
clean:
	@if [ -d "${OBJ_DIR}" ]; then						\
		echo $(RED)Cleaning"  "[$(OBJ_DIR)]...$(RESET);	\
		rm -rf ${OBJ_DIR};								\
		echo $(GREEN)Cleaned!$(RESET);					\
	fi

fclean:		clean
	@echo $(RED)Cleaning executables...
	@printf $(UP)$(CUT)
	@if [ -f "$(NAME)" ]; then							\
		echo $(RED)Cleaning"  "[$(NAME)]...$(RESET);	\
		rm -f $(NAME);									\
		echo $(GREEN)Cleaned!$(RESET);					\
	fi

re: fclean all

###############################################################################
###############################################################################

YELLOW		:=			"\033[33m"
RED			:=			"\033[33m"
GREEN		:=			"\033[32m"
RESET		:=			"\033[0m"
UP			:=			"\033[A"
CUT			:=			"\033[K"

###############################################################################
###############################################################################

.PHONY: all clean fclean re bonus
