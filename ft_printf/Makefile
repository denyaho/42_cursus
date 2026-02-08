# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 21:45:35 by daogawa           #+#    #+#              #
#    Updated: 2025/10/28 23:26:37 by daogawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_strlen.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_putunbr.c \
		ft_puthex.c ft_puthex_big.c ft_putchar.c ft_printf.c

OBJS = ft_strlen.o ft_putstr.o ft_putptr.o ft_putnbr.o ft_putunbr.o \
		ft_puthex.o ft_puthex_big.o ft_putchar.o ft_printf.o

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs libftprintf.a $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
