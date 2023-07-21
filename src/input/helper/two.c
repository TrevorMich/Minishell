/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:39:25 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/20 09:40:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	redir_type_err(char *s, int *i, char *redir_type, int skip_num)
{
	*i += skip_spaces(&s[*i + skip_num]) + skip_num;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (print_err("Token error", redir_type), -1);
	}
	return (*i);
}

int	redirection_err(char *input)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (input[i] != '\0' && value != -1)
	{
		if (input[i] == '\'' || input[i] == '"')
			i += skip_quotes(&input[i]);
		else if (input[i] == '<' && input[i + 1] != '<')
			value = redir_type_err(input, &i, "<", 1);
		else if (input[i] == '>' && input[i + 1] != '>')
			value = redir_type_err(input, &i, ">", 1);
		else if (input[i] == '<' && input[i + 1] == '<')
			value = redir_type_err(input, &i, "<<", 2);
		else if (input[i] == '>' && input[i + 1] == '>')
			value = redir_type_err(input, &i, ">>", 2);
		else
			i++;
	}
	if (value == -1)
		return (-1);
	return (0);
}
