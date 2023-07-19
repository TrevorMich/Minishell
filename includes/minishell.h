/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:03 by ioduwole          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/18 17:35:07 by doduwole         ###   ########.fr       */
=======
/*   Updated: 2023/07/18 20:13:26 by ioduwole         ###   ########.fr       */
>>>>>>> ab172e1d87a846e01056ecd62506e1a80744de29
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

# define MAX_TOKEN_SIZE 1024
typedef struct s_env //check israel_README
{
	char			*var; //variable name // change name to key
	char			*value; //variable value
	struct s_env	*next; //pointer to another t_env struct
	int				sorted;
}	t_env;

typedef struct s_cmdgroup
{
	char	**cmd;
	struct s_cmdgroup *next;

}	t_cmdgroup;

typedef struct s_args
{
	char type;
	char in_or_out;
	int len;
} t_args;

enum	e_token_types
{
	SEP,
	WORD,
	PIPE,
	IN_RDR,
	OUT_RDR,
	HERE_DOC,
	APP_RDR,
};

enum	e_quote_types
{
	NO_QUOT,
	SGL_QUOT,
	DBL_QUOT,
};

typedef struct s_idx
{
	int	i;
	int	j;
}	t_idx;

typedef struct s_token
{
	char			*string;
	int				e_token_type;
	int				e_quote_type;
	struct s_token	*next;
}					t_token;

typedef struct s_data //data struct
{
	char		*input; //string from readline
	t_env		*env;   //pointer to minishell environment variable struct
	t_cmdgroup	*cmdgroup;
	t_token		*token_lst;
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
void	ft_env(t_data *data, char **str);
void	cd(t_data *data, char **str);
void	cd_to_home(t_data *data);
void	pwd(void);
int		do_unset(t_data *data, char **var);
void	do_echo(char **str);
/**
 * BUILTIN UTILS
*/
void	update_env_value(t_env *list, char *var, char *new_value);
char	*get_current_dir(void);
void	update_dir(t_data *data);
void	update_oldpwd(t_data *data);
void	print_export(t_data *data);
int		smaller(char *str1, char *str2);
t_env	*set_min(t_data *data);
void	free_var(t_env *ptr);
int		is_update(t_data *data, char *tmp, char *value);
int		check_error(char **var, char c);
void	reset(t_data *data);
char	*ft_strdup2(const char *str, int len);

/**
 * PARSER ->
*/
void	parser(t_data *data);
/**
 *  PARSER -> QUOTES_REMOVAL
*/
void	remove_consecutive_quotes(char *input);
/**
 * PARSER -> TOKENIZER
*/
void	tokenizer(t_data *data);
/**
 * PARSER -> TOKENIZER -> HELPER
*/
t_token	*handle_words(char *s, int *i);
int		pick_word(char *str, char *char_set);
t_token	*handle_quotes(char *s, int *i);
t_token	*handle_pipe_or_sep(char *s, int *i, char pipe_or_sep);
t_token	*handle_single_rdr(char *s, int *i, char in_or_out);
t_token	*handle_double_rdr(char *s, int *i, char in_or_out);
/**
 * PARSER -> TOKENIZER -> UTILS
*/
void	token_add_back(t_token **lst, t_token *new);
t_token	*token_last(t_token *lst);
void	remove_quotes(char *s);
t_args	set_args(char type, char in_or_out, int len);
t_token *set_token(char *input, int i, t_args args);
void check_tokens(t_token *token);
/**
 * PARSER -> EXPANSION
*/
void	expand_token_lst(t_data *data);
char	*expand_token(char *token, t_data *data);
void	process_expansion(char *token, t_data *data, t_idx *idx, char **exp);
/**
 * PARSER -> EXPANSION -> UTILS
*/
// int	dollar_in_str(char *s);
/**
 * PARSER -> EXPANSION -> HELPER
*/
void	handle_exit_status(char **new_ptr, t_idx *idx);

void	copy_token_char(char **new_ptr, t_idx *idx, char c);
void	handle_single_dollar(char **new_ptr, t_idx *idx);
char	*get_exit_status(void);
void	handle_env_var(char **new_ptr, t_idx *idx, char *token, t_data *data);
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
