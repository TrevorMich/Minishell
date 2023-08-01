/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 08:22:06 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/30 21:22:07 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_free(t_data *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (data->env)
	{
		tmp = data->env;
		free(tmp->var);
		free(tmp->value);
		data->env = tmp->next;
		free(tmp);
		tmp = data->env;
	}
	free(data->input);
	free(data);
	exit (1);
}

void	clear_export(char *key, char **str)
{
	free(key);
	clear(str);
}
