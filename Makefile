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

NAME_BONUS = visual

NAME_FILLER = aryabenk.filler

SRC_FILLER = ./ft_read_filler.c ./main_filler.c ./ft_create_lst_filler.c \
                 ./ft_filler_heart.c ./ft_del_fill.c ./ft_check_filler.c

SRC_BONUS = ./bonus/ft_flag.c ./bonus/ft_main.c ./bonus/ft_print_bonus.c \
            ./bonus/ft_read.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME_BONUS) $(NAME_FILLER)

$(NAME_BONUS): $(SRC_BONUS)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC_BONUS) $(LIB) -o $(NAME_BONUS)

$(NAME_FILLER): $(SRC_FILLER)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC_FILLER) $(LIB) -o $(NAME_FILLER)

clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME_FILLER) $(NAME_BONUS)
	$(MLIB) fclean

re: fclean all