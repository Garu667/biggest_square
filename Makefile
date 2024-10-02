# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefiles                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaroudi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 19:50:33 by rmaroudi          #+#    #+#              #
#    Updated: 2024/08/28 19:50:34 by rmaroudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = files/algo.c \
       files/matrix.c \
       files/file.c \
       files/ft_split.c \
       files/main.c

NAME = bsq

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
