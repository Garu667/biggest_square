# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramaroud <ramaroud@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 15:29:20 by ramaroud          #+#    #+#              #
#    Updated: 2025/07/30 19:49:42 by tigondra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INC = -I files/header.h

SRCS = files/algo.c	\
       files/bsq.c	\
       files/check.c	\
       files/parse.c	\
       files/file.c	\
       files/utils.c	\
       files/main.c

NAME = bsq

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(INC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
