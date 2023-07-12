/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_err_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:39:04 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/12 15:24:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	space_err(char *input)
{
	int i;

	i = 0;
	while (input[i++] == ' ');
	if (input[i] == '\0')
		return (print_err("Empty command", " "), -1);
	return (0);
}

int	quote_err(char *input)
{
	int	i;
	int	dq_open;
	int	sq_open;

	i = 0;
	dq_open = 0;
	sq_open = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'' && !dq_open && !sq_open)
			sq_open = 1;
		else if (input[i] == '"' && !dq_open && !sq_open)
			dq_open = 1;
		else if (input[i] == '\'' && !dq_open && sq_open)
			sq_open = 0;
		else if (input[i] == '"' && dq_open && !sq_open)
			dq_open = 0;
		i++;
	}
	if (dq_open || sq_open)
		return (print_err("Unsupported quotes", " "), -1);
	return (0);
}

int	pipe_err(char *input)
{
	int	i;

	i = skip_spaces(input);
	if (input[i] == '|')
		return (print_err("Token error", "|"), -1);
	while (input[i] != '\0')
	{
		if (input[i] == '\'' || input[i] == '"')
			i += skip_quotes(&input[i]);
		else if (input[i] == '|')
		{
			i++;
			i += skip_spaces(&input[i]);
			if (input[i] == '|' || input[i] == '\0')
				return (print_err("Token error", "|"), -1);
		}
		else
			i++;
	}
	return (0);
}

int	special_char_err(char *input)
{
	int		i;
	char	*str;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'' || input[i] == '"')
			i += skip_quotes(&input[i]);
		else if (input[i] == ';' || input[i] == '&'
			|| input[i] == '{' || input[i] == '}'
			|| input[i] == '[' || input[i] == ']'
			|| input[i] == '(' || input[i] == ')'
			|| input[i] == '~' || input[i] == '%'
			|| input[i] == '\\' || input[i] == '*'
			|| input[i] == '^' || input[i] == '`')
		{
			str = ft_strdup(&input[i]);
			str[1] = '\0';
			return (
				print_err("Unsupported character", str), -1);
		}
		else
			i++;
	}
	return (0);
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
