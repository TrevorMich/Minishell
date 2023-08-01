/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:48:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/01 04:43:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	expand_token_lst(t_data *data)
{
	t_token	*tmp;
	char	*expanded_string;

	tmp = data->token_lst;
	while (tmp)
	{
		if (tmp->e_token_type != HERE_DOC && tmp->e_quote_type != SGL_QUOT
			&& ft_strchr(tmp->string, '$'))
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
