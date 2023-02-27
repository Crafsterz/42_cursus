# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 14:25:45 by mukhairu          #+#    #+#              #
#    Updated: 2023/02/24 11:49:17 by mukhairu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = server.c client.c
SRCDIR = .

BONUS_SRC = bonus/client.c bonus/server.c
BONUS_SRCDIR = bonus

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

GCC = gcc
CFLAGS = -Wall -Werror -Wextra

all: server client

server: server.o
	$(GCC) -o $@ $<

client: client.o
	$(GCC) -o $@ $<

$(BONUS_SRCDIR)/server: $(BONUS_SRCDIR)/server.o
	$(GCC) -o $@ $<

$(BONUS_SRCDIR)/client: $(BONUS_SRCDIR)/client.o
	$(GCC) -o $@ $<
	
bonus: $(BONUS_SRCDIR)/server $(BONUS_SRCDIR)/client
	

# $(SRCDIR)/%.o : $(SRCDIR)/%.c
# 	$(CC) -c $(CFLAGS) $?

$(BONUS_SRCDIR)/%.o : $(BONUS_SRCDIR)/%.c
	$(CC) -c  $(CFLAGS) -o $@ $<
	
clean:
	rm -f $(OBJ)
clean_bonus:
	rm -f $(BONUS_OBJ)
fclean: clean clean_bonus
	rm -f server client
	rm -f bonus/server bonus/client
re: fclean all

.PHONY: all bonus clean clean_bonus fclean re
