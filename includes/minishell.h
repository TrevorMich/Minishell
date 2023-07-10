/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:03 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/10 20:50:29 by ioduwole         ###   ########.fr       */
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
	char			*var; //variable name
	char			*value; //variable value
	struct s_env	*next; //pointer to another t_env struct
}	t_env;

typedef struct s_cmdgroup
{
	char	**cmd;
	struct s_cmdgroup *next;

}	t_cmdgroup;

typedef struct s_data //data struct
{
	char		*input; //string from readline
	t_env		*env;   //pointer to minishell environment variable struct
	t_cmdgroup	*cmdgroup;
}	t_data;

char	*ft_strjoin2(char const *s1, char const *s2, char c);
t_env	*find_path(t_data *data);
char	*get_current_dir(void);
void	do_env(t_data *data, char **str);
void	cd(t_data *data, char **str);
void	cd_to_home(t_data *data);
void	update_oldpwd(t_data *data);
void	update_env_value(t_env *list, char *var, char *new_value);
void	add_path(t_cmdgroup *group, char **path);
void	update_dir(t_data *data);
void	minishell(t_data *data);
void	clear(char **str);
void	create_env_list(t_data *data, char **envp);
void	insert_last(t_data *data, char *envp);
void	ft_env(t_data *data, char **str);
int		ft_strcmp(const char *s1, const char *s2);
void	free_all(t_data *data);
void	pwd(void);
void	get_path(t_data *data);
int		array_length(char **arr);
int		input_error(t_data *data);
int		space_err(char *input);

#endif
