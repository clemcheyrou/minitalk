NAME = client
NAME2 = server

SRC_PATH = sources/
OBJ_PATH = obj/

SRC_NAME = 	client.c			\
			utils.c				\

SRC2_NAME = server.c			\
			utils.c				\

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ2_NAME = $(SRC2_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
SRC2 = $(addprefix $(SRC_PATH),$(SRC2_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ2 = $(addprefix $(OBJ_PATH),$(OBJ2_NAME))

INC = -I includes

CC = cc
FLAGS = -Wall -Wextra -Werror -g
RM = @rm -rf

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
		@echo "Build $(NAME)"
		@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBS)

$(NAME2): $(OBJ2)
		@echo "Build $(NAME)"
		@$(CC) $(FLAGS) $(INC) $(OBJ2) -o $(NAME2) $(LIBS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(@D)
		$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
		$(RM) $(OBJ_PATH)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(NAME2)

re:	fclean
	make all

.PHONY: all clean fclean re