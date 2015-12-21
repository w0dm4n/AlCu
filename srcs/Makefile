# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 18:20:41 by frmarinh          #+#    #+#              #
#    Updated: 2015/12/15 00:49:10 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRCS = srcs/main.c

O_FILE = main.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) $(FLAGS) -I includes/
	@gcc $(O_FILE) $(FLAGS) -I includes/ -o $(NAME) -L includes/ -lft

clean :
	@rm -rf $(O_FILE)

fclean : clean
	@rm -rf $(NAME)

re:		fclean all
