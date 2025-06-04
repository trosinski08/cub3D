# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 01:54:44 by trosinsk          #+#    #+#              #
#    Updated: 2023/10/16 00:13:24 by trosinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILER
CC = cc

# Compiler flags
FLAGS = -Wall -Wextra -Werror

# Library name and module paths
NAME = libft.a
GNL = ./gnl42
PNT_F = ./ft_printf

# Explicit object files for GNL
# Assuming gnl42/Makefile compiles both and places them in its 'source' subdir
GNL_OBJS = $(GNL)/source/get_next_line.o
# Explicit object files for ft_printf
PRINTF_OBJS = \
    $(PNT_F)/mandatory/ft_printf.o \
    $(PNT_F)/mandatory/print_digit.o \
    $(PNT_F)/mandatory/print_h_up.o \
    $(PNT_F)/mandatory/print_hexa.o \
    $(PNT_F)/mandatory/print_point.o \
    $(PNT_F)/mandatory/print_string.o \
    $(PNT_F)/mandatory/ft_putchar.o \
    $(PNT_F)/mandatory/put_nbr_base.o \
    $(PNT_F)/mandatory/print_char.o \
    $(PNT_F)/utils/nbr_utils.o

# Include directories
INCLUDES = -I./include -I$(GNL)/include -I$(PNT_F)/include

#SOURCE FILES LIST
SRCS = ./gnl42/source/get_next_line.c \
		./gnl42/source/get_next_line_utils.c \
		./char/ft_atoi.c \
		./char/ft_isalnum.c \
		./char/ft_isalpha.c \
		./char/ft_isascii.c \
		./char/ft_isdigit.c \
		./char/ft_isprint.c \
		./char/ft_isspace.c \
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
		./string/ft_strcmp.c
	

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

# ========================= MAIN RULES ==========================

# Standard build - core libft functions
all: $(NAME)

# Compile the base library 
$(NAME): $(OBJS)
	@echo "\033[0;34mCompiling base libft functions...\033[0m"
	ar rcs $(NAME) $(OBJS)
	@echo "\033[0;32mBase libft compilation complete!\033[0m"

# Add bonus functions (linked lists) to the library
bonus: $(NAME) $(OBJSB)
	@echo "\033[0;34mAdding bonus functions to the library...\033[0m"
	ar rcs $(NAME) $(OBJSB)
	@echo "\033[0;32mBonus functions added successfully!\033[0m"

# Build printf module
printf:
	@echo "\\033[0;34mCompiling ft_printf module (if needed)...\\033[0m"
	@$(MAKE) -C $(PNT_F)
	@echo "\\033[0;34mAdding ft_printf objects to $(NAME)...\\033[0m"
	ar rcs $(NAME) $(PRINTF_OBJS)
	@echo "\\033[0;32mft_printf module compiled and added to $(NAME)!\\033[0m"

# Build get_next_line module
gnl:
	@echo "\\033[0;34mCompiling get_next_line module (if needed)...\\033[0m"
	@$(MAKE) -C $(GNL)
	@echo "\\033[0;34mAdding get_next_line objects to $(NAME)...\\033[0m"
	ar rcs $(NAME) $(GNL_OBJS)
	@echo "\\033[0;32mget_next_line module compiled and added to $(NAME)!\\033[0m"

# Build everything (complete library)
complete: all bonus printf gnl
	@echo "\\033[0;32mComplete libft library compiled successfully with all modules!\\033[0m"

# ========================= UTILITY RULES ==========================

# Compile object files from source files
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	@echo "\033[0;33mCleaning object files...\033[0m"
	rm -f $(OBJS)
	rm -f $(OBJSB)
	@make clean -C $(GNL)
	@make clean -C $(PNT_F)
	@echo "\033[0;32mObject files cleaned successfully!\033[0m"

# Full clean (objects and binary)
fclean: clean
	@echo "\033[0;33mRemoving library file...\033[0m"
	rm -f $(NAME)
	@make fclean -C $(GNL)
	@make fclean -C $(PNT_F)
	@echo "\033[0;32mAll generated files removed successfully!\033[0m"

# Recompile everything
re: fclean all

# Help command to display available targets
help:
	@echo "\033[1;37m==================== LIBFT MAKEFILE HELP ====================\033[0m"
	@echo "\033[0;36mmake all\033[0m        : Compile core libft functions"
	@echo "\033[0;36mmake bonus\033[0m      : Add linked list functions to the library"
	@echo "\033[0;36mmake printf\033[0m     : Compile ft_printf module"
	@echo "\033[0;36mmake gnl\033[0m        : Compile get_next_line module"
	@echo "\033[0;36mmake complete\033[0m   : Compile everything into one library"
	@echo "\033[0;36mmake clean\033[0m      : Remove object files"
	@echo "\033[0;36mmake fclean\033[0m     : Remove object files and library"
	@echo "\033[0;36mmake re\033[0m         : Recompile everything"
	@echo "\033[0;36mmake help\033[0m       : Display this help message"
	@echo "\033[1;37m=============================================================\033[0m"

.PHONY: all bonus printf gnl complete clean fclean re help