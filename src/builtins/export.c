/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:50:28 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/21 14:07:01 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_strchr_int(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s || !c)
		return (-1);
	while (s[i] != 0 && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char **handle_value(char **var)
{
	char	**val;
	char 	*str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	val = malloc(array_length(var) * sizeof(char **));
	while (var[i])
	{
		str = ft_strchr(var[i++], '=');
		if (str)
			val[j++] = str;
	}
	return (val);
}

char **handle_key(char **var, char **ptr)
{
	int i;
	int j;
	int k;
	char	**key;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	key = malloc(array_length(var) * sizeof(char **));
	while (var[i])
	{
		str = ft_strchr(var[i], '=');
		if (str)
		{

			key[j++] = ft_strdup2(var[i], ptr[k] - var[i]);
			k++;
		}
		i++;
	}
	return (key);
}

int	export(t_data *data, char **var)
{
	char	**value;
	char	**key;
	char	**str;
	
	if (array_length(var) == 1)
		return (print_export(data), reset(data), 1);
	value = handle_value(var);
	key = handle_key(var, value);
	str = malloc(array_length(var) * sizeof(char **));

	int i;
	i = 0;
	// while (tmp[i] && ptr[i])
	// {
	// 	printf("%s = %s\n", tmp[i], ptr[i]);
	// 	i++;
	// }

	if (!check_error(var, 'e'))
		return (printf("minishell: export: '%s': not a valid identifier\n",
				var[1]), 0);
	while (value[i] && key[i])
	{
		str[i] = ft_strjoin(key[i], value[i]);
		i++;
	}
	
	 i = 0;
	// int j = 0;
	// while (var[i])
	// 	str[j++] = ft_split(*(var++), '\0');
	// i = 0;
	// while (str[i])
	// 	printf("%s\n", str[i++]);
		
	// if (!is_update(data, key, value + 1))
	// 	create_env_list(data, str);
	// free(key);
	// clear(str);
	return (1);
}

int	is_update(t_data *data, char *tmp, char *value)
{
	t_env	*ptr;

	ptr = data->env;
	while (ptr)
	{
		if (!ft_strcmp(ptr->value, tmp))
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
	return NULL;
}
