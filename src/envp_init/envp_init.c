/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:48:11 by ioduwole          #+#    #+#             */
/*   Updated: 2023/08/01 09:06:26 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	create_env_list(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		insert_last(data, envp[i]);
		i++;
	}
}

void	insert_last(t_data *data, char *envp)
{
	t_env	*new;
	t_env	*last;

	new = malloc(sizeof(t_env));
	new->var = ft_substr(envp, 0, ft_strchr(envp, '=') - envp);
	new->value = ft_strdup(ft_strchr(envp, '=') + 1);
	new->next = NULL;
	if (data->env == NULL)
		data->env = new;
	else
	{
		last = data->env;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
