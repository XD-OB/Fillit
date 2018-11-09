# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 03:14:56 by obelouch          #+#    #+#              #
#    Updated: 2018/11/07 03:15:02 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
OBJ = *.o
HEAD = tetris.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEAD)
	@gcc -c $(FLAG) $(SRC)
	@gcc $(FLAG) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
