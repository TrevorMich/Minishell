/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:46:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/01 04:47:43 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	tokenizer(t_data *data)
{
	t_token		*token;
	t_token		**token_lst;
	int			i;
	char		*input;

	i = 0;
	input = data->input;
	token_lst = &data->token_lst;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
			token = handle_quotes(&input[i], &i);
		else if (input[i] == '|' || input[i] == ' ')
			token = handle_pipe_or_sep(&input[i], &i, input[i]);
		else if ((input[i] == '>' && input[i + 1] != '>') || \
				(input[i] == '<' && input[i + 1] != '<'))
			token = handle_single_rdr(input, &i, input[i]);
		else if ((input[i] == '<' && input[i + 1] == '<') || \
				(input[i] == '>' && input[i + 1] == '>'))
			token = handle_double_rdr(input, &i, input[i]);
		else
			token = handle_words(input, &i);
		token_add_back(token_lst, token);
	}
}
