#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 16:40:55 by aryabenk          #+#    #+#              #
#    Updated: 2018/03/13 16:40:56 by aryabenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = aryabenk.filler

SRC = ./ft_read_filler.c ./main_filler.c ./ft_create_lst_filler.c \
        ./ft_filler_heart.c ./ft_del_fill.c ./ft_check_filler.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all