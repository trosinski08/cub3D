CC		:= cc
NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX	:= ./MLX42
SRCS 	:= main.c checks.c garbage_collector.c errors.c utils.c parser.c \
			key_hook.c mlx.c init.c player.c parser_utils.c setters.c \
			vertical_ray.c horizontal_ray.c
LIBFT	:= ./libft
GNL		:= ./gnl42
# BONUS	:= bonus.c

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address
INCLUDE := -L $(LIBFT) -lft -L $(GNL) -lgnl
OBJS	:= ${SRCS:.c=.o}
# BOBJS	:= ${BONUS:.c=.o}

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
	make -sC $(GNL)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(INCLUDE) -o $(NAME)

# bonus:
# $(NAME): $(OBJS) $(BOBJS)
# 	make -C $(LIBFT)
# 	@$(CC) $(OBJS) $(BOBJS) $(LIBS) $(HEADERS) $(INCLUDE) -o $(NAME)

clean:
	@rm -rf $(OBJS) $(BOBJS)
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(GNL) && $(MAKE) clean
	@rm -rf MLX42

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean
	@cd $(GNL) && $(MAKE) fclean
	

re: clean all

.PHONY: all, clean, fclean, re, libmlx, bonus