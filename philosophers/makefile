NAME = philosophers
GCC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread -g3 
INCLUDES = -Iincludes

MAIN = main.c philos.c utils.c

SRCS = $(addprefix main/, $(MAIN))
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(GCC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

