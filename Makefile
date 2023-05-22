# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 15:03:03 by mukhairu          #+#    #+#              #
#    Updated: 2023/05/18 17:55:52 by mukhairu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#main.c shouldn't be a .o file together with the OBJ command
MAIN = main.c
SRC = input_stacks.c	checker.c	swap.c	push.c	rotate.c	rotate_tog.c\
		index.c small_sort.c	radix_sort.c	utils.c

#SRCDIR = .

#libft
LIBFT = -Llibft -lft
#MAKE_LIBFT

#ft_printf
FT_PRINTF = -Lft_printf -lftprintf

INCLUDES = -I includes

#The .o is the object that check if the file is updated
OBJ = $(addprefix obj/, $(SRC:.c=.o))

GCC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): ${OBJ} ${MAIN}
	make -C libft
	make -C ft_printf
	$(GCC) $(CFLAGS) $(INCLUDES) -o $@ ${MAIN} ${OBJ} ${LIBFT} ${FT_PRINTF}

debug: ${SRC} ${MAIN}
	make -C libft
	make -C ft_printf
	$(GCC) $(CFLAGS) $(INCLUDES) -o $@ ${MAIN} ${SRC} ${LIBFT} ${FT_PRINTF} -fsanitize=address -g3

obj/%.o: ./%.c
	@mkdir -p ${@D}
	@${GCC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	@rm -rf obj
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	rm -f debug

re: fclean all

.PHONY: all debug clean fclean re
