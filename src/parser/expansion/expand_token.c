/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:42:31 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 17:44:29 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*expand_token(char *token, t_data *data)
{
	char	*exp;
	t_idx	idx;

	exp = malloc(MAX_TOKEN_SIZE);
	if (!token)
	{
		print_err("Malloc failed in expand_token func","");
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
