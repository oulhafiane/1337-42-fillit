# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 02:32:29 by zoulhafi          #+#    #+#              #
#    Updated: 2018/10/30 13:46:56 by zoulhafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

__SRC = srcs/

__INCLUDES = includes

_SRC = check_block.c check_lines.c check_tetriminoes2.c main.c print_tetriminoes.c check_input.c check_tetriminoes1.c lists.c optimize.c utility.c

SRC = $(patsubst %.c, $(__SRC)%.c, $(_SRC))

OBJ = $(patsubst %.c, %.o, $(_SRC))

FLAG = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME) : $(__INCLUDES)/fillit.h
	make -C libft/ fclean && make -C libft/
	gcc $(FLAG) -c $(SRC) -I$(__INCLUDES)
	gcc -o $(NAME) $(OBJ) -L libft -lft

clean:
	rm -Rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -Rf $(NAME)
	rm -Rf libft/libft.a

re: fclean all
