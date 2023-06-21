# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 09:00:17 by ioduwole          #+#    #+#              #
#    Updated: 2023/06/21 17:46:47 by ioduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	*.c
		
CC  =  gcc

CFLAGS = -Werror -Wall -Wextra

//Copy readline library into this path so there's no conflict in compilation
RD_LIB = -I/usr/local/Cellar/readline/8.1.2/include -L/usr/local/Cellar/readline/8.1.2/lib -lreadline

LIB_DIR = ./libft/

LIBFT	= ./libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
		$(CC) $(CFLAGS) $(RD_LIB) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all
