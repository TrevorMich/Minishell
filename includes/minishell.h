/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:03 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/05 21:54:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_env //check israel_README
{
	char* var; //variable name
	char* value; //variable value
	struct s_env* next; //pointer to another t_env struct
}	t_env;

typedef struct s_data //data struct
{
	char* input; //string from readline
	t_env* env;   //pointer to minishell environment variable struct
}	t_data;

char* ft_strjoin2(char const* s1, char const* s2);
void	clear_string(char** str);
void	create_env_list(t_data* data, char** envp);
void	insert_last(t_data* data, char* envp);
void	print_list(t_data* data, char** envp);
int		ft_strcmp(const char* s1, const char* s2);
void	free_all(t_data* data);
#endif