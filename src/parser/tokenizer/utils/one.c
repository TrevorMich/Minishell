/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/01 04:50:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

t_args	set_args(char type, char in_or_out, int len)
{
	t_args	args;

	args.len = len;
	args.in_or_out = in_or_out;
	args.type = type;
	return (args);
}

void	handle_token_type(t_token **token, t_args args)
{
	if (args.type == 'w')
		(*token)->e_token_type = WORD;
	else
		remove_quotes((*token)->string);
	if (args.in_or_out == '<' && args.type == 'h')
		(*token)->e_token_type = HERE_DOC;
	else if (args.in_or_out == '>' && args.type == 'h')
		(*token)->e_token_type = APP_RDR;
	else if (args.in_or_out == '<' && args.type == 'r')
		(*token)->e_token_type = IN_RDR;
	else if (args.in_or_out == '>' && args.type == 'r')
		(*token)->e_token_type = OUT_RDR;
}

void	handle_quote_type(t_token **token, char input)
{
	if (input == '\'')
		(*token)->e_quote_type = SGL_QUOT;
	else if (input == '"')
		(*token)->e_quote_type = DBL_QUOT;
}

t_token	*set_token(char *input, int i, t_args args)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize helper function", "");
		g_exit_status = 13;
		return (NULL);
	}
	token->string = ft_substr(input, i, args.len);
	handle_token_type(&token, args);
	handle_quote_type(&token, *input);
	token->next = NULL;
	return (token);
}
