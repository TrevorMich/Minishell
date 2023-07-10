# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 09:00:17 by ioduwole          #+#    #+#              #
#    Updated: 2023/07/10 14:38:51 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# SRC =	$(wildcard *.c) $(wildcard */*.c) $(wildcard */*/*.c) $(wildcard */*/*/*.c) 

SRC := $(wildcard *.c */*.c */*/*.c */*/*/*.c)

CC  =  gcc

CFLAGS = -Wall -Wextra -Werror 

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
		$(CC) $(CFLAGS) $(RD_LIB) $? -o $@

$(LIBFT):
	@make all -C $(LIB_DIR)
	@make clean -C ${LIB_DIR}

clean:
	@make clean -C $(LIB_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all
