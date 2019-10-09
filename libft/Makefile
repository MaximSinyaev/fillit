#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolen <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 15:10:57 by aolen             #+#    #+#              #
#    Updated: 2019/09/10 17:55:47 by aolen            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FUNCS_1 = ft_memset\
		ft_bzero\
		ft_memcpy\
		ft_memccpy\
		ft_memmove\
		ft_memchr\
		ft_memcmp\
		ft_strlen \
		ft_strdup \
		ft_strcpy \
		ft_strncpy \
		ft_strcat \
		ft_strncat \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower
FUNCS_2 = \
		ft_memalloc \
		ft_memdel \
		ft_strnew \
		ft_strdel \
		ft_strclr \
		ft_striter \
		ft_striteri \
		ft_strmap \
		ft_strmapi \
		ft_strequ \
		ft_strnequ \
		ft_strsub \
		ft_strjoin \
		ft_strtrim \
		ft_strsplit \
		ft_itoa \
		ft_putchar \
		ft_putnbr \
		ft_putstr \
		ft_putendl \
		ft_putchar_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_putendl_fd
FUNCS_3 = \
		ft_lstnew \
		ft_lstdelone \
		ft_lstdel \
		ft_lstadd \
		ft_lstiter \
		ft_lstmap
FUNCS_A = \
		ft_strlcpy \
		ft_power \
		ft_putnbr_base \
		ft_swap \
		ft_isspace \
		ft_strupcase \
		ft_strlowcase \
		ft_realloc
ALL_FUNCS = $(FUNCS_1) $(FUNCS_2) $(FUNCS_3) $(FUNCS_A)
NAME = libft.a
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(ALL_FUNCS)))
OBJS = $(addsuffix .o, $(ALL_FUNCS))
SRC_PATH = ./srcs/
INCLUDE_PATH = ./includes/
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_PATH)
RED = "\033[1;31m"
PURPLE = "\033[1;35m"
GREEN = "\033[1;32m"
NOCOLOR = "\033[0m"

all: $(NAME)

compile:
	@echo $(PURPLE)">>> Compiling..."$(NOCOLOR)

$(OBJS): %.o: $(SRC_PATH)%.c
	gcc -c $(CFLAGS) $^

$(NAME): $(OBJS) #compile
	@echo $(PURPLE)">>> Packing..."$(NOCOLOR)
	ar rc $(NAME) $?
	ranlib $(NAME)
	@echo $(GREEN)">>>LIBFT compilled!"$(NOCOLOR)
clean:
	@echo $(PURPLE)">>> Deleting libft object files.."$(NOCOLOR)
	rm -f $(OBJS)
fclean: clean
	@echo $(PURPLE)">>> Deleting libft..."$(NOCOLOR)
	rm -f $(NAME)
re: fclean all
