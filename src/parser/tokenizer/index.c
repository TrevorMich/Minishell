/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:46:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:28:54 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

///@test
// echo dre, echo "dre", echo 'dre'
// echo drey > readme, echo "drey" > readme, echo 'drey' > readme
// echo < readme, echo < readme, echo < readme
// t_token **token_lst, char *input
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
