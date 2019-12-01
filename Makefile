# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 10:48:59 by dmukaliy          #+#    #+#              #
#    Updated: 2019/11/23 15:14:27 by dmukaliy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
	validate.c\
	trim_input.c\
	support.c\
	fillit.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		make -C libft/ 
		$(CC) $(FLAGS)  -I libft/ -c $(SRC)
		$(CC) -o $(NAME) $(OBJ) $(FLAGS) -I libft/ -L libft/ -lft
		make clean -C libft
		rm -f $(OBJ)

clean: 
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

