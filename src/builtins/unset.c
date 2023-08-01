/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:27:41 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:16:56 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_unset(t_data *data, char **var)
{
	t_env	*ptr;
	t_env	*ptr2;

	ptr = data->env;
	if (!check_error(var, 'u'))
		return (printf("minishell: unset: '%s': not a valid identifier\n",
				var[1]), 0);
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

int	check_error(char **var, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = var[1];
	if (!str)
		return (0);
	if (c == 'u')
	{
		while (str[i])
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '=' || str[i] == '.'
				|| str[i] == '?')
				return (0);
			i++;
		}
	}
	while (str[i])
	{
		if (str[0] == '=' || str[i] == '+' || str[i] == '-' || str[i] == '.'
			|| str[i] == '?')
			return (0);
		i++;
	}
	return (1);
}

void	free_var(t_env *ptr)
{
	free(ptr->var);
	free(ptr->value);
	free(ptr);
}
