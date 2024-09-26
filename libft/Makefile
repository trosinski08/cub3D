# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 01:54:44 by trosinsk          #+#    #+#              #
#    Updated: 2024/06/27 02:02:28 by trosinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILER
CC = cc

#COMPILATION FLAGS
FLAGS = -Wall -Wextra -Werror

#PROGRAM NAME
NAME = libft.a

#SOURCE FILES LIST
SRCS = ./char/ft_atoi.c \
		./char/ft_isalnum.c \
		./char/ft_isalpha.c \
		./char/ft_isascii.c \
		./char/ft_isdigit.c \
		./char/ft_isprint.c \
		./char/ft_itoa.c \
		./char/ft_tolower.c \
		./char/ft_toupper.c \
		./memory/ft_bzero.c \
		./memory/ft_calloc.c \
		./memory/ft_memchr.c \
		./memory/ft_memcmp.c \
		./memory/ft_memcpy.c \
		./memory/ft_memmove.c \
		./memory/ft_memset.c \
		./print/ft_putchar_fd.c \
		./print/ft_putendl_fd.c \
		./print/ft_putnbr_fd.c \
		./print/ft_putstr_fd.c \
		./string/ft_split.c \
		./string/ft_strchr.c \
		./string/ft_strdup.c \
		./string/ft_striteri.c \
		./string/ft_strjoin.c \
		./string/ft_strlcat.c \
		./string/ft_strlcpy.c \
		./string/ft_strlen.c \
		./string/ft_strmapi.c \
		./string/ft_strncmp.c \
		./string/ft_strnstr.c \
		./string/ft_strrchr.c \
		./string/ft_strtrim.c \
		./string/ft_substr.c \
	

#BONUS FUNCTIONS
BNS = ./bonus/ft_lstnew.c \
		./bonus/ft_lstadd_front.c \
		./bonus/ft_lstsize.c \
		./bonus/ft_lstlast.c \
		./bonus/ft_lstadd_back.c \
		./bonus/ft_lstdelone.c \
		./bonus/ft_lstclear.c \
		./bonus/ft_lstiter.c \
		./bonus/ft_lstmap.c \

#OBJECT FILES CREATIONS
OBJS = $(SRCS:.c=.o)
OBJSB = $(BNS:.c=.o)

#ALL RULE
all: $(NAME)

#LIBRARY RULES
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

#BONUS COMPILER
bonus: $(NAME) $(OBJSB)
	@ar rcs $(NAME) $(OBJSB)

#OBJECT FILES COMPILING
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJSB)

fclean: clean
	@rm -f $(NAME)

#RULE TO REKOMIPILE
re: fclean all

.PHONY: all clean fclean re