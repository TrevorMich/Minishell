/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:57:32 by ioduwole          #+#    #+#             */
/*   Updated: 2023/06/24 18:58:52 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin2(char const	*s1, char const	*s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*dst;

	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	dst = malloc(sizeof(char) * size);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i++] = '/';
	j = 0;
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
