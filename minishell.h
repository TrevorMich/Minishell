/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:03 by ioduwole          #+#    #+#             */
/*   Updated: 2023/06/26 17:31:11 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "libft/libft.h"
#include <string.h>
typedef struct	s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
	
	
} t_env;

typedef struct	s_data
{
	char	*input;
	int 	i;
	char	**tmp;
	t_env	*env;

} t_data;


char	*ft_strjoin2(char const	*s1, char const	*s2);
void	clear_string(char **str);
t_env	*create_env_node(char **data);
void	add_env(t_env **list, t_env *new);
#endif