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
LIBS = ./print_f/libftprintf.a

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
		@make -C ./print_f/
		@echo "Build $(NAME)"
		@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBS)

$(NAME2): $(OBJ2)
		@make -C ./print_f/
		@echo "Build $(NAME)"
		@$(CC) $(FLAGS) $(INC) $(OBJ2) -o $(NAME2) $(LIBS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(@D)
		$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
		@make clean -C ./print_f/
		$(RM) $(OBJ_PATH)

fclean:	clean
		make fclean -C ./print_f/ clean 
		$(RM) $(NAME)
		$(RM) $(NAME2)

re:	fclean
	make all

.PHONY: all clean fclean re