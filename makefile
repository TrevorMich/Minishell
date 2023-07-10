# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 09:00:17 by ioduwole          #+#    #+#              #
#    Updated: 2023/07/10 18:37:34 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC := $(wildcard *.c */*.c */*/*.c */*/*/*.c)

CC  =  gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

UNAME := $(shell uname -m)

ifeq ($(UNAME),arm64)
    RD_LIB = -I/opt/homebrew/opt/readline/include -L/opt/homebrew/opt/readline/lib -lreadline
endif
ifeq ($(UNAME),x86_64)
    RD_LIB = -I/usr/local/Cellar/readline/8.1.2/include -L/usr/local/Cellar/readline/8.1.2/lib -lreadline
endif

LIB_DIR = ./includes/libft/

LIBFT	= ./includes/libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	@$(CC) $(CFLAGS) $(RD_LIB) $(SRC) $(LIBFT) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(LIBFT):
	@make all -C $(LIB_DIR)
	@make clean -C ${LIB_DIR}

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@$(MAKE) -C $(LIB_DIR) fclean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
