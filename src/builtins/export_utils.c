/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:01:46 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/30 08:26:33 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reset(t_data *data)
{
	t_env	*tmp_ptr;

	tmp_ptr = data->env;
	while (tmp_ptr)
	{
		tmp_ptr->sorted = 0;
		tmp_ptr = tmp_ptr->next;
	}
}

int	smaller(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str2)
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] < str2[i])
			return (1);
		else if (str1[i] > str2[i])
			return (0);
		i++;
	}
	if (str1[i] && !str2[i])
		return (0);
	return (1);
}

char	*ft_strdup2(const char *str, int len)
{
	int		i;
	char	*dup;

	i = 0;
	dup = ft_calloc(len + 1, sizeof(char *));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**get_key(char *var, char *key, char **value)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc((array_length(var) * sizeof(char **)) + 1);
	while (value[i] && key[i])
	{
		str[i] = ft_strjoin(key[i], value[i]);
		i++;
	}
	return (str);
}
