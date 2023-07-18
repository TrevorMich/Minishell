/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:51:10 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 17:46:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_exit_status(char **new_ptr, t_idx *idx)
{
	char	*exit_status;

	exit_status = get_exit_status();
	ft_strcpy(&(*new_ptr)[idx->j], exit_status);
	idx->j += ft_strlen(exit_status);
	free(exit_status);
	idx->i += 2;
}

void	handle_single_dollar(char **new_ptr, t_idx *idx)
{
	(*new_ptr)[(idx->j)++] = '$';
	idx->i += 2;
}

void	handle_env_var(char **new_ptr, t_idx *idx, char *token, t_data *data)
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

void	copy_token_char(char **new_ptr, t_idx *idx, char c)
{
	(*new_ptr)[(idx->j)++] = c;
}

