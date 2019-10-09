#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolen <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 15:10:57 by aolen             #+#    #+#              #
#    Updated: 2019/09/24 13:19:58 by aolen            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FUNCS = \
		fillit \
		print_errors \
		get_next_line \
		input_check \
		tetrimino_collection \
		ft_root \
		tetris \
		map_funcs
NAME = fillit
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FUNCS)))
OBJS = $(addsuffix .o, $(FUNCS))
SRC_PATH = ./
INCLUDE_PATH = ./includes/
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_PATH)
LIBFT = lidft.a
LIBS = -L./libft -lft
RED = "\033[1;31m"
PURPLE = "\033[1;35m"
GREEN = "\033[1;32m"
NOCOLOR = "\033[0m"

all: $(NAME)

compile:
	@echo $(PURPLE)">>> Compiling..."$(NOCOLOR)

$(LIBFT):
	make -C ./libft

$(OBJS): %.o: $(SRC_PATH)%.c
	gcc -c $(CFLAGS) $^

$(NAME): compile $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo $(GREEN)">>> Succes!"$(NOCOLOR)
clean:
	@echo $(PURPLE)">>> Deleting object files.."$(NOCOLOR)
	rm -f $(OBJS)
	make -C ./libft clean
fclean: clean
	@echo $(PURPLE)">>> Deleting fillit..."$(NOCOLOR)
	make -C ./libft fclean
	rm -f $(NAME)
	@echo $(GREEN)">>> fillit deleted"$(NOCOLOR)'\n'
re: fclean all
