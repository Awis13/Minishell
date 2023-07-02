CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell
INCLUDES = -I./include
SRCS =  src/main.c \
        src/get_next_line.c \
        src/get_next_line_utils.c \
        src/ft_printf.c \
        src/ft_printf_utils.c \
        $(wildcard src/libft/*.c)
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
