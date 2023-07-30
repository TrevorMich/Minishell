/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:34:08 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:12:02 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_env(t_data *data, char **str)
{
	t_env	*tmp;

	if (array_length(str) >= 2)
	{
		printf("minishell: env: '%s': No such file or directory\n", str[1]);
		g_exit_status = 127;
		return ;
	}
	tmp = data->env;
	while (tmp)
	{
		printf("%s=", tmp->var);
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
	g_exit_status = 0;
}

int	array_length(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
