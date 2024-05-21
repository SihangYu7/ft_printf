# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 11:40:08 by siyu              #+#    #+#              #
#    Updated: 2024/05/21 12:17:26 by siyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
# ****************************************************************************
HEADER = ft_printf.h
# ****************************************************************************
NAME = libftprintf.a

SRC_PRINTF = ft_printf.c ft_putadrs.c ft_putchar.c ft_puthex.c ft_putstr.c ft_putunsigned.c ft_putnbr.c

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
# ****************************************************************************
all: $(NAME)

$(NAME): $(OBJ_PRINTF)
	ar rc $(NAME) $(OBJ_PRINTF)


%.o: %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_PRINTF)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, bonus, clean, fclean, re



