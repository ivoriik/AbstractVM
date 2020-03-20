NAME		=	abstract-vm
FLAGS		= 	-Wall -Werror -Wextra
GCC	        =	g++ -std=c++11

INC_DIR		=	inc/
SRC_DIR		=	src/
OBJ_DIR		= 	obj/

SRC 		=	Exceptions.cpp \
                FactoryClass.cpp \
                InputHandler.cpp \
                main.cpp \
                Parcer.cpp \
                VmStack.cpp \
                Token.cpp \
                Lexer.cpp

OBJ 		= 	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

INC 		= 	-I $(INC_DIR)

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(GCC) $(INC) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@$(GCC) $(INC) $(FLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all