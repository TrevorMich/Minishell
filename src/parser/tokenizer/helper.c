/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:45:46 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/17 18:58:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_token *set_token(char *input, char type, int *i, int len, char in_or_out)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize helper function", "");
		// g_exit_status = 13;
		return (NULL);
	}
	token->string = ft_substr(input, *i, len);
	if (type == 'o')
		token->type = WORD;
	else
		remove_quotes(token->string);
	if (in_or_out == '<' && type == 'h')
		token->type = HERE_DOC;
	else if (in_or_out == '>' && type == 'h')
		token->type = APP_RED;
	if (in_or_out == '<' && type == 'r')
		token->type = IN_RED;
	else if (in_or_out == '>' && type == 'r')
		token->type = OUT_RED;
	if (input[*i] == '\'')
	{
		token->quote_type = S_Q;
		printf("Single quote\n");
	}
	else if (input[*i] == '"')
	{
		token->quote_type = D_Q;
		printf("Double quote\n");
	}
	token->next = NULL;
	printf("string: %s\ntype: %d\nquote_type: %d\n\n", token->string, token->quote_type, token->type);
	return (token);
}

t_token	*init_word(char *input, int *i)
{
	t_token	*token;
	int		len;

	len = pick_word(&input[*i], " '\"<>|");
	token = set_token(input, 'o', i, len, ' ');
	*i += len;
	return (token);
}

t_token	*init_in_quotes(char *input, int *i)
{
	t_token	*token;
	int		len;
	int		val;

	val = 1;
	len = skip_quotes(input);
	token = set_token(input, 'o', &val, len - 2, ' ');
	*i += len;
	return (token);
}

t_token	*init_pipe_or_sep(char *input, int *i, char pipe_or_sep)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize_helper","");
		// g_exit_status = 13;
		return (NULL);
	}
	token->string = ft_calloc(1, sizeof(char));
	if (pipe_or_sep == ' ')
	{
		*i += skip_spaces(input);
		token->type = SEP;
	}
	else
	{
		*i = *i + 1;
		token->type = PIPE;
	}
	token->next = NULL;
	return (token);
}

t_token	*init_single_redirection(char *input, int *i, char in_or_out)
{
	t_token	*token;
	int		len;

	*i += skip_spaces(&input[*i + 1]) + 1;
	len = pick_word(&input[*i], " <>|");
	token = set_token(input, 'o', i, len, in_or_out);
	*i += len;
	return (token);
}

t_token	*init_double_redirection(char *input, int *i, char in_or_out)
{
	t_token	*token;
	int		len;

	*i += skip_spaces(&input[*i + 2]) + 2;
	len = pick_word(&input[*i], " <>|");
	token = set_token(input, 'o', i, len, in_or_out);
	*i += len;
	return (token);
}
