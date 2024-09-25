NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 32
LIBFT = ../libft
HEADERS = -I ../libft -I ./include
LIBS = -L $(LIBFT) -lft
SRC = ./source/get_next_line.c \
	./source/get_next_line_utils.c
OBJS = $(SRC:.c=.o)
# BNO = $(BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# bonus: $(BNO)
# @ar rcs $(NAME) $(BNO)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BNO)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
