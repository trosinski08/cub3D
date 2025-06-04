NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 32
HEADERS = -I ./include -I ../include
SRC = ./source/get_next_line.c ./source/get_next_line_utils.c
OBJS = $(SRC:.c=.o)
# BNO = $(BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
