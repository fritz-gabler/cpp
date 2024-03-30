NAME			=		sedIsForLosers

###############################################################################
###############################################################################

CC				=		c++
CFLAGS			=		-Wall -Werror -Wextra -g
CPPFLAG			=		-std=c++98
HEADERS			=		-I./include -I./include/structure					\
						-I./include/errorMessage -I./include/object

###############################################################################
###############################################################################

VPATH			:=		src src/errorHandling src/inputCheck				\
						src/structure src/setupStruct src/objectFunctions	\
						src/fileManipulation

SRC_FILE		=		main.cpp
SRC_FILE_FUNC	=		file.cpp
SRC_SETUP		=		setupStruct.cpp
SRC_INPUT		=		inputCheck.cpp
SRC_ERROR		=		errorOccured.cpp
SRC_MANIPUL		=		isInputString.cpp replaceStringOneWithStringTow.cpp

SRC				=		$(SRC_FILE) $(SRC_INPUT) $(SRC_SETUP) $(SRC_ERROR)	\
						$(SRC_FILE_FUNC) $(SRC_MANIPUL)

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
