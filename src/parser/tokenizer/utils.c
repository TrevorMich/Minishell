/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:45:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 10:48:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	token_add_back(t_token **lst, t_token *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		token_last(*lst)->next = new;
}

t_token	*token_last(t_token *lst)
{
	t_token	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	remove_quotes(char *s)
{
	int	len;

	len = ft_strlen(s);
	if ((len >= 2 && s[0] == '"' && s[len - 1] == '"')
		|| (len >= 2 && s[0] == '\'' && s[len - 1] == '\''))
	{
		ft_memmove(s, s + 1, len - 2);
		s[len - 2] = '\0';
	}
}

t_args set_args(char type, char in_or_out, int len)
{
	t_args args;

	args.len = len;
	args.in_or_out = in_or_out;
	args.type = type;
	return (args);
}

t_token *set_token(char *input, int i, t_args args)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize helper function", "");
		// g_exit_status = 13;
		return (NULL);
	}
	token->string = ft_substr(input, i, args.len);
	if (args.type == 'w')
	{
		token->e_token_type = WORD;
		printf("\033[2;37m""WORD\n""\033[0m");
	}
	else
	{
		remove_quotes(token->string);
		printf("\033[2;37m""REMOVE QUOTE\n""\033[0m");
	}
	if (args.in_or_out == '<' && args.type == 'h')
	{
		token->e_token_type = HERE_DOC;
		printf("\033[2;37m""HERE_DOC\n""\033[0m");
	}
	else if (args.in_or_out == '>' && args.type == 'h')
	{
		token->e_token_type = APP_RDR;
		printf("\033[2;37m""APP_RED\n""\033[0m");
	}
	else if (args.in_or_out == '<' && args.type == 'r')
	{
		token->e_token_type = IN_RDR;
		printf("\033[2;37m""IN_RED\n""\033[0m");
	}
	else if (args.in_or_out == '>' && args.type == 'r')
	{
		token->e_token_type = OUT_RDR;
		printf("\033[2;37m""OUT_RED\n""\033[0m");
	}

	if (*input == '\'')
	{
		token->e_quote_type = SGL_QUOT;
		printf("\033[2;37m""Single quote\n""\033[0m");
	}
	else if (*input == '"')
	{
		token->e_quote_type = DBL_QUOT;
		printf("\033[2;37m""Double quote\n""\033[0m");
	}
	token->next = NULL;
	printf("string: %s\ntoken_type: %d\nquote_type: %d\n\n", token->string, token->e_token_type, token->e_quote_type);
	return (token);
}
