# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouay <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 12:22:12 by adouay            #+#    #+#              #
#    Updated: 2022/08/04 14:07:03 by adouay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc -Wall -Werror -Wextra

SRC = pipex.c \
	child.c	\
	here_doc.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L libft/. -lft -I libft/. -o $(NAME)

%.o: %.c
	$(CC) -c $^ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all