/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:55:23 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:19:15 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_token_list(t_token **token_list)
{
	t_token	*tmp;

	tmp = *token_list;
	while (*token_list != NULL)
	{
		if (tmp->string)
			free(tmp->string);
		tmp = tmp->next;
		free(*token_list);
		*token_list = tmp;
	}
}

void	free_ins(t_ins **ptr)
{
	t_ins	*tmp;

	tmp = *ptr;
	while (tmp)
	{
		free(tmp->str);
		*ptr = tmp->next;
		free(tmp);
		tmp = *ptr;
	}
}

void	free_outs(t_outs **ptr)
{
	t_outs	*tmp;

	tmp = *ptr;
	while (tmp)
	{
		free(tmp->str);
		*ptr = tmp->next;
		free(tmp);
		tmp = *ptr;
	}
}

void	free_cmdgroup(t_data *data)
{
	t_cmdgroup	*tmp;

	tmp = data->cmdgroup;
	while (tmp)
	{
		if (tmp->cmd)
			clear(tmp->cmd);
		if (tmp->ins)
			free_ins(&tmp->ins);
		if (tmp->outs)
			free_outs(&tmp->outs);
		if (tmp->str)
			free(tmp->str);
		data->cmdgroup = tmp->next;
		free(tmp);
		tmp = data->cmdgroup;
	}
}

void	free_exec(t_data *data)
{
	unlink("here_doc.txt");
	free(data->input);
	free_token_list(&data->token_lst);
	free_cmdgroup(data);
}
