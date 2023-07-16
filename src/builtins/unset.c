/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:27:41 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/16 12:46:14 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	do_unset(t_data *data, char **var)
{
	t_env	*ptr;
	t_env	*ptr2;

	ptr = data->env;
	if (!check_unset(var))
		return (0);
	if (!ft_strcmp(ptr->var, var[1]))
	{
		data->env = ptr->next;
		return (free_var(ptr), 1);
	}
	while (ptr->next)
	{
		ptr2 = ptr->next;
		if (!ft_strcmp(ptr2->var, var[1]))
		{
			ptr->next = ptr2->next;
			return (free_var(ptr2), 1);
		}
		ptr = ptr->next;
	}
	return (0);
}

int	check_unset(char **var)
{
	int	i;
	char *str;

	i = 0;
	str = var[1];

	if (!str)
		return (0);
	while (str[i] == '+' || str[i] == '-' || str[i] == '?' || str[i] =='.')
	{
		printf("minishell: unset: '%s': not a valid identifier\n", str);
		return (0);
	}
	return (1);
}

void	free_var(t_env *ptr)
{
	free(ptr->var);
	free(ptr->value);
	free(ptr);
}
