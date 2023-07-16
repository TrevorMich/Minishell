/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:03 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/15 10:43:07 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <string.h>
# include "libft/libft.h"
# include "errno.h"

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

/**
 * MINISHELL PROGRAM
*/
void	minishell(t_data *data);
int		exec_minishell(t_data *data);

/**
 * UTILITIES
*/
char	*ft_strjoin2(char const *s1, char const *s2, char c);
t_env	*find_path(t_data *data);
void	add_path(t_cmdgroup *group, char **path);
void	clear(char **str);
void	create_env_list(t_data *data, char **envp);
void	insert_last(t_data *data, char *envp);
int		ft_strcmp(const char *s1, const char *s2);
void	free_all(t_data *data);
void	get_path(t_data *data);
int		array_length(char **arr);
/**
 * BUILTINS
*/
void	do_env(t_data *data, char **str);
void	update_env_value(t_env *list, char *var, char *new_value);
void	ft_env(t_data *data, char **str);
void	cd(t_data *data, char **str);
void	cd_to_home(t_data *data);
char	*get_current_dir(void);
void	update_dir(t_data *data);
void	update_oldpwd(t_data *data);
void	pwd(void);
int		do_unset(t_data *data, char **var);
int		check_unset(char **var);
void	free_var(t_env *ptr);
/**
 * INPUT ERRORS
*/
int		input_error(t_data *data);
int		space_err(char *input);
int		quote_err(char *input);
int		pipe_err(char *input);
int		special_char_err(char *input);
int		redirection_err(char *input);
int		redir_type_err(char *s, int *i, char *redir_type, int skip_num);
/**
 * PRINT ERROR
*/
void	print_err(char *err_msg, char *str);
/**
 * SKIPS
*/
int		skip_spaces(char *input);
int		skip_quotes(char *input);

#endif
