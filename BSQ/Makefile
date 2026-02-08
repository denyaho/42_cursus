NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  dynamic_cal.c \
		ft_putchar.c \
		ft_split.c \
		is_valid_argc.c \
		main.c \
		map_length.c \
		reflection_map.c \
		subfunction.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

.PHONY:
	all clean fclean re
