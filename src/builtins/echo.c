/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:50:48 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:10:27 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_echo(char **str)
{
	char	**tmp_str;
	int		i;

	i = 0;
	if (array_length(str) == 1)
	{
		printf("\n");
		return ;
	}
	tmp_str = &str[1];
	if (tmp_str)
	{
		if (!ft_strcmp(tmp_str[0], "-n"))
			tmp_str = &tmp_str[1];
		while (tmp_str[i])
		{
			printf("%s", tmp_str[i++]);
			if (tmp_str[i])
				printf(" ");
		}
	}
	if (!(!ft_strcmp(str[1], "-n")))
		printf("\n");
}
