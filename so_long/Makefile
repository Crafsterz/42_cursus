NAME = so_long
GCC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
MLX = -lmlx -framework OpenGL -framework AppKit
INCLUDES = -Iincludes -Ilibft
LIBFT = -Llibft -lft

# MAIN = main_2#-fsanitize=address -fno-omit-frame-pointer
# UTILS = get_next_line mapping checks

# # SRCS = $(MAIN) $(UTILS)

MAIN = main.c render.c
UTILS = get_next_line.c mapping.c checks.c \
			checks_utils.c moves.c gnrl_utils.c flood_fill.c

SRCS = $(addprefix game/, $(MAIN)) $(addprefix utils/, $(UTILS))
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(GCC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

# %.o: %.c
# 	@mkdir -p $(@D)
# 	$(GCC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(GCC) $(CFLAGS) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	@make fclean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
