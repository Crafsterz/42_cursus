# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 14:25:45 by mukhairu          #+#    #+#              #
#    Updated: 2023/03/28 12:32:50 by mukhairu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c	ft_putchar.c	ft_putstr.c \
		ft_putnbr.c	ft_itoa_base.c	ft_hexdec.c \
		ft_uns_dec.c	ft_pointer.c	ft_itoa.c \
		ft_calloc.c	ft_strlen.c

#these are all the .o files created
OBJ_SRC = $(SRC:.c=.o)

NAME = libftprintf.a

CC = gcc

AR = ar -crs

RM = rm -rf

INCLUDE = -I libftprintf.h

CFLAGS = -Wall -Werror -Wextra

.c.o: 
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDE)

all: $(NAME)

$(NAME):	$(OBJ_SRC)
	@$(AR) $(NAME) $(OBJ_SRC)
	@echo "All is complete"
	
clean:
	@$(RM) $(OBJ_SRC)
	@$(RM) obj

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm: norminette -R CheckForbiddenSourceHeader

.PHONY : all clean fclean re 
# The makefile will need to be checked again later
