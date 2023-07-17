/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:48:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/16 14:52:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	expand_token_lst(t_data *data)
{
	t_token	*tmp;
	char	*expanded_string;

	tmp = data->token_lst;
	while (tmp != NULL)
	{
		if (tmp->type != HERE_DOC && tmp->quote_type != S_Q
			&& dollar_in_str(tmp->string))
		{
			expanded_string = expand_token(tmp->string, data);
			if (expanded_string != NULL)
			{
				free(tmp->string);
				tmp->string = expanded_string;
			}
		}
		tmp = tmp->next;
	}
}