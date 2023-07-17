/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:51:10 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/17 08:55:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	process_expansion(char *token, t_data *data, t_idx *idx, char **exp)
{
	if (token[idx->i] == '$')
	{
		if (token[idx->i + 1] == '?')
			init_exit_status(exp, idx);
		else if (token[idx->i + 1] == '$')
			init_single_dollar(exp, idx);
		else if (ft_isalnum(token[idx->i + 1]) || token[idx->i + 1] == '_')
			init_env_var(exp, idx, token, data);
		else
			copy_token_char(exp, idx, token[idx->i++]);
	}
	else
		copy_token_char(exp, idx, token[idx->i++]);
}

char	*expand_token(char *token, t_data *data)
{
	char	*exp;
	t_idx	idx;

	exp = malloc(MAX_TOKEN_SIZE);
	if (!token)
	{
		printf("minishell: malloc failed in expander\n");
		// g_exit_status = 13;
		return (NULL);
	}
	idx.i = 0;
	idx.j = 0;
	while (token[idx.i] != '\0')
	{
		process_expansion(token, data, &idx, &exp);
	}
	exp[idx.j] = '\0';
	return (exp);
}

void	init_exit_status(char **new_ptr, t_idx *idx)
{
	char	*exit_status;

	exit_status = get_exit_status();
	ft_strcpy(&(*new_ptr)[idx->j], exit_status);
	idx->j += ft_strlen(exit_status);
	free(exit_status);
	idx->i += 2;
}

void	init_env_var(char **new_ptr, t_idx *idx, char *token, t_data *data)
{
	char	*var;
	char	*env_var;

	idx->i++;
	var = create_var_from_token(token, idx);
	if (!var)
		return ;
	env_var = find_envp_value(data->env, var);
	if (env_var != NULL)
		copy_env_var_value(new_ptr, idx, env_var);
	free(var);
}

char	*create_var_from_token(char *token, t_idx *idx)
{
	char	*var;
	int		var_len;

	var = malloc(ft_strlen(token) + 1);
	if (!token)
	{
		printf("minishell: malloc failed in expander_init2\n");
		// g_exit_status = 13;
		return (NULL);
	}
	var_len = 0;
	while (ft_isalnum(token[idx->i]) || token[idx->i] == '_')
	{
		var[var_len++] = token[idx->i];
		idx->i++;
	}
	if (var_len == 0)
	{
		free(var);
		return (NULL);
	}
	var[var_len] = '\0';
	return (var);
}

char	*find_envp_value(t_env *env_lst, char *var_name)
{
	while (env_lst != NULL)
	{
		if (ft_strcmp(env_lst->var, var_name) == 0)
			return (env_lst->value);
		env_lst = env_lst->next;
	}
	return (NULL);
}
