NAME = philosophers
GCC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
INCLUDES = -Iincludes

MAIN = main.c philos.c utils.c
UTILS = 

SRCS = $(addprefix main/, $(MAIN) $(addprefix utils/, $(UTILS)))
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

