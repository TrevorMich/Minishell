/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:01:39 by ioduwole          #+#    #+#             */
/*   Updated: 2023/06/26 17:30:56 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_env_node(char **data)
{
	t_env	*content;
	
	content = malloc(sizeof(t_env));
	if (!data)
		return NULL;
	content->var = data[0];
	printf("%s\n", content->var);
	if (!data[1])
		return NULL;
	else
		content->value = data[1];
	content->next = NULL;
	return (content);
}

void	add_env(t_env **list, t_env *new)
{
	if (!list || !new)
		return ;
	printf("%s\n", (char *)*list);	
}