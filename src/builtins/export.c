/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:50:28 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/30 23:59:34 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_var(char **var)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (var[i])
	{
		j = 0;
		while (var[i][j])
		{
			if (var[i][0] == '=' || var[i][j] == '?' || var[i][j] == '-'
				|| var[i][j] == '.')
			{
				g_exit_status = 1;
				return (printf("zsh: no matches found: '%s'\n", var[i]), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	do_export(t_data *data, char **var)
{
	if (array_length(var) == 1)
		return (print_export(data), reset(data), 1);
	if (!get_key(data, var))
		return (0);
	return (1);
}

int	is_update(t_data *data, char *tmp, char *value)
{
	t_env	*ptr;

	ptr = data->env;
	while (ptr)
	{
		if (!ft_strcmp(ptr->var, tmp))
		{
			if (!(!ft_strcmp(ptr->value, value)))
			{
				free(ptr->value);
				ptr->value = ft_strdup(value);
			}
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

void	print_export(t_data *data)
{
	t_env	*tmp;
	t_env	*tmp1;
	t_env	*min;

	tmp = data->env;
	while (tmp)
	{
		tmp1 = data->env;
		min = set_min(data);
		while (tmp1)
		{
			if (!smaller(min->var, tmp1->var) && !tmp1->sorted)
				min = tmp1;
			tmp1 = tmp1->next;
		}
		min->sorted = 1;
		printf("declare -X %s=", min->var);
		printf("\"%s\"\n", min->value);
		tmp = tmp->next;
	}
}

t_env	*set_min(t_data *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp)
	{
		if (!tmp->sorted)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
