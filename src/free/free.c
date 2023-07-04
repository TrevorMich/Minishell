/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:55:23 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/03 20:45:00 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all(t_data *data)
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
