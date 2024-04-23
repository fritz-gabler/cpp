NAME			=		harlFiltr

###############################################################################
###############################################################################

CC				=		c++
CFLAGS			=		-Wall -Werror -Wextra
CPPFLAG			=		-std=c++98
HEADERS			=		-I./include -I./include/objects -I./include/defines

###############################################################################
###############################################################################

VPATH			:=		src src/objectFunctions src/inputCheck	src/print	\
						src/identifyLevel

SRC_MAIN		=		main.cpp
SRC_HARL		=		Harl.cpp
SRC_CHECK		=		inputCheck.cpp
SRC_PRINT		=		printErrorMessage.cpp
SRC_IDENT		=		identifyLevel.cpp

SRC				=		$(SRC_MAIN) $(SRC_HARL) $(SRC_CHECK) $(SRC_PRINT)	\
						$(SRC_IDENT)

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
	@$(CC)	$(CFLAGS) $(CPPFLAG) $(OBJ) -o $(NAME)
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
