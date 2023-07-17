/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:45:46 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/17 12:53:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_token	*init_word(char *input, int *i)
{
	t_token	*token;
	int		len;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize helper function", "");
		// g_exit_status = 13;
		return (NULL);
	}
	len = pick_word(&input[*i], " '\"<>|");
	token->string = ft_substr(input, *i, len);
	token->type = WORD;
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
	*i += len;
	printf("string: %s\ntype: %d\nquote_type: %d\n\n", token->string, token->quote_type, token->type);
	return (token);
}

t_token	*init_in_quotes(char *input, int *i)
{
	t_token	*token;
	int		len;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize_helper", "");
		// g_exit_status = 13;
		return (NULL);
	}
	len = skip_quotes(input);
	token->string = ft_substr(input, 1, len - 2);
	token->type = WORD;
	if (*input == '\'')
		token->quote_type = S_Q;
	else if (*input == '"')
		token->quote_type = D_Q;
	token->next = NULL;
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

	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
	{
		print_err("Malloc failed in tokenize_helper", "");

		// g_exit_status = 13;
		return (NULL);
	}
	*i += skip_spaces(&input[*i + 1]) + 1;
	len = pick_word(&input[*i], " <>|");
	token->string = ft_substr(input, *i, len);
	remove_quotes(token->string);
	if (in_or_out == '<')
		token->type = IN_RED;
	else if (in_or_out == '>')
		token->type = OUT_RED;
	if (input[*i] == '\'')
		token->quote_type = S_Q;
	else if (input[*i] == '"')
		token->quote_type = D_Q;
	token->next = NULL;
	*i += len;
	return (token);
}

t_token	*init_double_redirection(char *input, int *i, char in_or_out)
{
	t_token	*token;
	int		len;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenizer", "");
		// g_exit_status = 13;
		return (NULL);
	}
	*i += skip_spaces(&input[*i + 2]) + 2;
	len = pick_word(&input[*i], " <>|");
	token->string = ft_substr(input, *i, len);
	remove_quotes(token->string);
	if (in_or_out == '<')
		token->type = HERE_DOC;
	else if (in_or_out == '>')
		token->type = APP_RED;
	if (input[*i] == '\'')
		token->quote_type = S_Q;
	else if (input[*i] == '"')
		token->quote_type = D_Q;
	token->next = NULL;
	*i += len;
	return (token);
}
