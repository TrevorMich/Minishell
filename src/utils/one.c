/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:48:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/17 12:56:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skip_spaces(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	return (i);
}

int	skip_quotes(char *input)
{
	int		i;
	char	quote_type;

	i = 1;
	quote_type = input[0];
	while (input[i] != quote_type)
		i++;
	return (i + 1);
}

void	print_err(char *err_msg, char *str)
{
	if (str[0] == ' ')
	{
		printf("\033[0;31m""Error:""\033[3m""\033[2;37m"" %s\n""\033[0m", err_msg);
		return ;
	}
	printf("\033[0;31m""Error:""\033[3m""\033[2;37m"" %s: '%s'\n""\033[0m",
		err_msg, str);
}

int	pick_word(char *str, char *char_set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (char_set[j])
		{
			if (str[i] == char_set[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
