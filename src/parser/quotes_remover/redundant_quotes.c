/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundant_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:19:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:29:20 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	remove_consecutive_quotes(char *input)
{
	int	head;
	int	tail;
	int	open_quote;

	head = 0;
	tail = 0;
	open_quote = 0;
	while (input[head])
	{
		if (!open_quote && ((input[head] == '"' && input[head + 1] == '"')
				|| (input[head] == '\'' && input[head + 1] == '\'')
			))
			head++;
		else
		{
			if (input[head] == '"' || input[head] == '\'')
				open_quote = !open_quote;
			input[tail] = input[head];
			tail++;
		}
		head++;
	}
	input[tail] = '\0';
}
