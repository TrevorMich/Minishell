/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:45:46 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 09:29:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

///@test
// echo dre, echo "dre", echo 'dre'
// echo drey > readme, echo "drey" > readme, echo 'drey' > readme
// echo < readme, echo < readme, echo < readme


t_token *set_token(char *input, char type, int i, int len, char in_or_out)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		print_err("Malloc failed in tokenize helper function", "");
		// g_exit_status = 13;
		return (NULL);
	}
	token->string = ft_substr(input, i, len);
	if (type == 'w')
	{
		token->e_token_type = WORD;
		printf("\033[2;37m""WORD\n""\033[0m");
	}
	else
	{
		remove_quotes(token->string);
		printf("\033[2;37m""REMOVE QUOTE\n""\033[0m");
	}
	if (in_or_out == '<' && type == 'h')
	{
		token->e_token_type = HERE_DOC;
		printf("\033[2;37m""HERE_DOC\n""\033[0m");
	}
	else if (in_or_out == '>' && type == 'h')
	{
		token->e_token_type = APP_RDR;
		printf("\033[2;37m""APP_RED\n""\033[0m");
	}
	else if (in_or_out == '<' && type == 'r')
	{
		token->e_token_type = IN_RDR;
		printf("\033[2;37m""IN_RED\n""\033[0m");
	}
	else if (in_or_out == '>' && type == 'r')
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

t_token	*handle_words(char *input, int *i)
{
	t_token	*token;
	int		len;

	len = pick_word(&input[*i], " '\"<>|");
	token = set_token(input, 'w', *i, len, ' ');
	*i += len;
	return (token);
}

t_token	*handle_quotes(char *input, int *i)
{
	t_token	*token;
	int		len;

	len = skip_quotes(input);
	token = set_token(input, 'w', 1, len - 2, ' ');
	*i += len;
	return (token);
}

t_token	*handle_pipe_or_sep(char *input, int *i, char pipe_or_sep)
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
		token->e_token_type = SEP;
	}
	else
	{
		*i = *i + 1;
		token->e_token_type = PIPE;
	}
	token->next = NULL;
	return (token);
}

t_token	*handle_single_rdr(char *input, int *i, char in_or_out)
{
	t_token	*token;
	int		len;

	*i += skip_spaces(&input[*i + 1]) + 1;
	len = pick_word(&input[*i], " <>|");
	token = set_token(input, 'r', *i, len, in_or_out);
	*i += len;
	return (token);
}

t_token	*handle_double_rdr(char *input, int *i, char in_or_out)
{
	t_token	*token;
	int		len;

	*i += skip_spaces(&input[*i + 2]) + 2;
	len = pick_word(&input[*i], " <>|");
	token = set_token(input, 'h', *i, len, in_or_out);
	*i += len;
	return (token);
}
