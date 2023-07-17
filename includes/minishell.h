/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:03 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/17 12:34:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <string.h>
# include "libft/libft.h"

# define MAX_TOKEN_SIZE 1024
typedef struct s_env //check israel_README
{
	char			*var; //variable name // change name to key
	char			*value; //variable value
	struct s_env	*next; //pointer to another t_env struct
}	t_env;

typedef struct s_cmdgroup
{
	char	**cmd;
	struct s_cmdgroup *next;

}	t_cmdgroup;



enum	e_token_types
{
	SEP,
	WORD,
	PIPE,
	IN_RED,
	OUT_RED,
	HERE_DOC,
	APP_RED,
};

enum	e_quote_types
{
	NO_Q,
	S_Q,
	D_Q,
};

typedef struct s_idx
{
	int	i;
	int	j;
}	t_idx;

typedef struct s_token
{
	char			*string; // change name to cmd
	int				type;
	int				quote_type;
	struct s_token	*next;
}					t_token;

typedef struct s_data //data struct
{
	char		*input; //string from readline
	t_env		*env;   //pointer to minishell environment variable struct
	t_cmdgroup	*cmdgroup;
	t_token		*token_lst;
}	t_data;

char	*ft_strjoin2(char const *s1, char const *s2, char c);
t_env	*find_path(t_data *data);
char	*get_current_dir(void);
void	do_env(t_data *data, char **str);
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
void	get_path(t_data *data);
int		array_length(char **arr);
int		exec_minishell(t_data *data);
/**
 * BUILTINS
*/
void	cd(t_data *data, char **str);
void	pwd(void);
/**
 * PARSER FUNCTIONS
*/
void	parser(t_data *data);
void	remove_consecutive_quotes(char *input);
// token functions
void	tokenizer(t_token **token_lst, char *input);
void	token_add_back(t_token **lst, t_token *new);
t_token	*token_last(t_token *lst);
void	remove_quotes(char *s);
int		pick_word(char *str, char *possible_sep);
t_token	*init_in_quotes(char *s, int *i);
t_token	*init_pipe_or_sep(char *s, int *i, char pipe_or_sep);
t_token	*init_single_redirection(char *s, int *i, char in_or_out);
t_token	*init_double_redirection(char *s, int *i, char in_or_out);
void	expand_token_lst(t_data *data);
t_token	*init_word(char *s, int *i);
char	*expand_token(char *token, t_data *data);
void	process_expansion(char *token, t_data *data, t_idx *idx, char **exp);
int	dollar_in_str(char *s);
void	copy_token_char(char **new_ptr, t_idx *idx, char c);
void	init_single_dollar(char **new_ptr, t_idx *idx);
void	init_exit_status(char **new_ptr, t_idx *idx);
char	*get_exit_status(void);
void	init_env_var(char **new_ptr, t_idx *idx, char *token, t_data *data);
char	*create_var_from_token(char *token, t_idx *idx);
void	copy_env_var_value(char **new_ptr, t_idx *idx, char *env_var);
char	*find_envp_value(t_env *env_lst, char *var_name);
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
