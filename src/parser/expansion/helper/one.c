/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:40:46 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/01 04:31:38 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	process_expansion(char *token, t_data *data, t_idx *idx, char **exp)
{
	if (token[idx->i] == '$')
	{
		if (token[idx->i + 1] == '?')
			handle_exit_status(exp, idx);
		else if (token[idx->i + 1] == '$')
			handle_single_dollar(exp, idx);
		else if (ft_isalnum(token[idx->i + 1]) || token[idx->i + 1] == '_')
			handle_env_var(exp, idx, token, data);
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
		print_err("Malloc failed in expand_token func", "");
		g_exit_status = 13;
		return (NULL);
	}
	idx.i = 0;
	idx.j = 0;
	while (token[idx.i] != '\0')
		process_expansion(token, data, &idx, &exp);
	exp[idx.j] = '\0';
	return (exp);
}
