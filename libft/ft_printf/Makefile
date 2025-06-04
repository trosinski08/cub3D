# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 01:54:44 by trosinsk          #+#    #+#              #
#    Updated: 2024/06/11 23:13:43 by trosinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILER
CC = cc

#COMPILATION FLAGS
FLAGS = -Wall -Wextra -Werror

#PROGRAM NAME
NAME := libftprintf.a
INCLUDE := -I./include -I../include
LIBFT_INCLUDE := -I../include
#SOURCE FILES LIST
SRCS = ./mandatory/ft_printf.c  \
		./mandatory/print_digit.c \
		./mandatory/print_h_up.c \
		./mandatory/print_hexa.c \
		./mandatory/print_point.c \
		./mandatory/print_string.c \
		./mandatory/ft_putchar.c \
		./mandatory/put_nbr_base.c \
		./mandatory/print_char.c \
		./utils/nbr_utils.c

	
BNS = ./bonus/flag_spec.c \
		./bonus/nbr_utils_bonus.c \
		./bonus/nbr_utils_bonus_2.c
	
#PLIKI OBIEKTOWE
OBJS = $(SRCS:.c=.o)
OBJSB = $(BNS:.c=.o)

#ALL RULE
all: $(NAME)

#RULE DO ZROBIENIA BIBLIOTEKI
$(NAME): $(OBJS)
	@$(MAKE) -C ../
	@cp ../libft.a $(NAME)
	@touch $(NAME)
	@ar rcs $(NAME) $(OBJS)
	
bonus: $(NAME) $(OBJSB)
	@touch $(NAME)
	@ar rcs $(NAME) $(OBJSB)

#RULE DO STWORZENIA PLIKOW OBIEKTOWYCH
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)
# $(MAKE) -C $(LIBFT) clean

#RULE DO CZYSZCZENIA WSZYSTKIEGO
fclean: clean
	rm -f $(NAME)
# $(MAKE) -C $(LIBFT) fclean
#RULE DO REKOMIPLACJI
re: fclean all

.PHONY: all clean fclean re bonus init