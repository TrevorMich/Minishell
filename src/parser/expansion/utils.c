/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:49:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 17:48:59 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// int	dollar_in_str(char *s)
// {
// 	while (*s)
// 	{
// 		if (*s == '$')
// 			return (1);
// 		s++;
// 	}
// 	return (0);
// }

char	*get_exit_status(void)
{
	char	*value;

	value = ft_itoa(13);
	// value = ft_itoa(g_exit_status);
	if (!value)
		return (NULL);
	return (value);
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

void	copy_env_var_value(char **new_ptr, t_idx *idx, char *env_var)
{
	ft_strcpy(&(*new_ptr)[idx->j], env_var);
	idx->j += ft_strlen(env_var);
}
