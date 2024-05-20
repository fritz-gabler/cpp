NAME			:=		scalar_converter

###############################################################################
###############################################################################

CXX				=		c++
CXXFLAGS		=		-Wall -Werror -Wextra -std=c++98 -g
HEADERS			=		-I./include -I./include/objects

###############################################################################
###############################################################################

VPATH			:=		src src/objectFunctions src/input_parsing             \
								src/log_function src/string_check

SRC_MAIN		=		main.cpp
SRC_LOG		  =		log.cpp
SRC_PARS		=		input_parsing.cpp
SRC_OBJS		=		ScalarConverter.cpp
SRC_CHECK   =   is_str_convertible_to_int.cpp

SRC				=		$(SRC_MAIN) $(SRC_PARS) $(SRC_LOG) $(SRC_OBJS) $(SRC_CHECK)

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
	@$(CXX)	$(OBJ) -o $(NAME)
	@echo	$(GREEN)Success [$(NAME)] is compiled$(RESET)

$(OBJ_DIR)/%.o: %.cpp
	@echo $(YELLOW)Compiling [$@]...$(RESET)
	@printf $(UP)$(CUT)
	@if	[ ! -d "{OBJ_DIR}" ]; then						\
		mkdir -p _obj;									\
	fi
	@$(CXX) $(CXXFLAGS) -c $< $(HEADERS) -o $@

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

YELLOW			:=			"\033[33m"
RED				:=			"\033[33m"
GREEN			:=			"\033[32m"
RESET			:=			"\033[0m"
UP				:=			"\033[A"
CUT				:=			"\033[K"

###############################################################################
###############################################################################

.PHONY: all clean fclean re bonus
