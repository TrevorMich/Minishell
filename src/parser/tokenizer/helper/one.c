/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:35:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:26:43 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

t_token	*handle_words(char *input, int *i)
{
	t_token		*token;
	t_args		args;
	int			len;

	len = pick_word(&input[*i], " '\"<>|");
	args = set_args('w', ' ', len);
	token = set_token(input, *i, args);
	*i += len;
	return (token);
}

t_token	*handle_quotes(char *input, int *i)
{
	t_token	*token;
	t_args	args;
	int		len;

	len = skip_quotes(input);
	args = set_args('w', ' ', len - 2);
	token = set_token(input, 1, args);
	*i += len;
	return (token);
}

t_token	*handle_pipe_or_sep(char *input, int *i, char pipe_or_sep)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize_helper", "");
		g_exit_status = 13;
		return (NULL);
	}
	token->string = ft_calloc(1, sizeof(char));
	if (pipe_or_sep == ' ')
	{
		*i += skip_spaces(input);
		token->e_token_type = SEP;
	}
	else
	{
		*i += 1;
		token->e_token_type = PIPE;
	}
	token->next = NULL;
	return (token);
}

t_token	*handle_single_rdr(char *input, int *i, char in_or_out)
{
	t_token	*token;
	t_args	args;
	int		len;

	*i += skip_spaces(&input[*i + 1]) + 1;
	len = pick_word(&input[*i], " <>|");
	args = set_args('r', in_or_out, len);
	token = set_token(input, *i, args);
	*i += len;
	return (token);
}

t_token	*handle_double_rdr(char *input, int *i, char in_or_out)
{
	t_token	*token;
	t_args	args;
	int		len;

	*i += skip_spaces(&input[*i + 2]) + 2;
	len = pick_word(&input[*i], " <>|");
	args = set_args('h', in_or_out, len);
	token = set_token(input, *i, args);
	*i += len;
	return (token);
}
