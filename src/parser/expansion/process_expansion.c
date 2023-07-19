/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:42:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 17:43:46 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
