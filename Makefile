CC		:= cc
NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX	:= ./MLX42
SRCS 	:= main.c checks.c garbage_collector.c errors.c utils.c parser.c \
			key_hook.c draw.c init.c raytrace.c parser_utils.c setters.c \
			vertical_ray.c horizontal_ray.c render_utils.c parser_validation.c \
			parser_helpers.c init_helpers.c parser_validation.c
LIBFT	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
INCLUDE := -L $(LIBFT) -lft
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -sC $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	make -sC $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(INCLUDE) -o $(NAME)

clean:
	@rm -rf $(OBJS) $(BOBJS)
	@cd $(LIBFT) && $(MAKE) clean
	@rm -rf MLX42

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, bonus