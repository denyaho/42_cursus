# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 21:45:35 by daogawa           #+#    #+#              #
#    Updated: 2025/12/21 16:29:38 by daogawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = detach_list.c find_target.c ft_atoi.c ft_lstsize.c ft_split.c count_to_top.c ft_strlen.c \
		get_target_in_b.c index.c ft_lstnew.c push_swap.c push.c move_min_to_top.c \
		rotate.c sort.c stack_init.c swap_list.c duplicate.c ft_lstclear.c get_target_in_a.c

OBJS = detach_list.o find_target.o ft_atoi.o ft_lstsize.o ft_split.o count_to_top.o ft_strlen.o \
		get_target_in_b.o index.o ft_lstnew.o push_swap.o push.o move_min_to_top.o \
		rotate.o sort.o stack_init.o swap_list.o duplicate.o ft_lstclear.o get_target_in_a.o
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
