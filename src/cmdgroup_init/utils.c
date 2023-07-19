/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:49:50 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/19 05:50:35 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin2(char const	*s1, char const	*s2, char c)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	dst = malloc(sizeof(char) * size);
	while (s1 && s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i++] = c;
	while (s2[j])
		dst[i++] = s2[j++];
	return (dst);
}

void	clear(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
