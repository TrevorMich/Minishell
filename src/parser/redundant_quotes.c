/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundant_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:19:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/14 19:55:43 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_consecutive_quotes(char *input)
{
	int	i;
	int	j;
	int	open_quote;

	i = 0;
	j = 0;
	open_quote = 0;
	while (input[i] != '\0')
	{
		if (!open_quote && ((input[i] == '"' && input[i + 1] == '"')
				|| (input[i] == '\'' && input[i + 1] == '\'')))
					i += 2;
		else
		{
			if (input[i] == '"' || input[i] == '\'')
				open_quote = !open_quote;
			input[j] = input[i];
			i++;
			j++;
		}
	}
	input[j] = '\0';
}