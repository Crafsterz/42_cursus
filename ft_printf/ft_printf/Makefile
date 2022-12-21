# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 14:25:45 by mukhairu          #+#    #+#              #
#    Updated: 2022/12/21 19:58:41 by mukhairu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c	ft_putchar.c	ft_putstr.c \
		ft_putnbr.c	ft_itoa_base.c	ft_hexdec.c \
		ft_uns_dec.c	ft_pointer.c	ft_itoa.c \
		ft_calloc.c	ft_strlen.c

MAIN_SRC = $(SRC:.c=.o)

NAME = libftprintf.a

CC = gcc

AR = ar -crs

RM = rm -rf

INCLUDE = libft.h

CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDE)

all: $(NAME)

$(NAME):	$(MAIN_SRC)
			$(AR) $(NAME) $(MAIN_SRC)
	@mkdir ./prtf_obj/
	@mv $(MAIN_SRC) prtf_obj

clean:
		$(RM) $(MAIN_SRC)
		$(RM) prtf_obj

fclean: clean
		$(RM) $(NAME)

re: fclean all

# The makefile will need to be checked again later
