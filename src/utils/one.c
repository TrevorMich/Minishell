/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:48:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:21:05 by ioduwole         ###   ########.fr       */
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

void	print_welcome(int argc, char **argv)
{
	if (argc > 1 || argv[1])
		exit(printf("error: minishell can't take argument(s)\n") - 39);
	printf(" *********************************\n");
	printf("|                                 |\n");
	printf("|       Welcome to""\033[1;34m"" Minishell""\033[0m""      |\n");
	printf("|               ""\033[3m""\033[2;37m""by""\033[0m"\
	"                |\n");
	printf("|        ""\033[33m""Israel ""\033[0m""&""\033[0;33m"" Dare"\
	"\033[0m""            |\n");
	printf("|                                 |\n");
	printf(" ********************************* \n");
}
