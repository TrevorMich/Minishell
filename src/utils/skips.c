/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skips.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:48:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/12 09:08:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	skip_spaces(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	return (i);
}

int	skip_quotes(char *input)
{
	int	i;
	char quote_type;

	i = 1;
	quote_type = input[0];
	while (input[i] != quote_type)
		i++;
	return (i + 1);
}
