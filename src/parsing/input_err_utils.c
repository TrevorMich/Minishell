/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_err_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:39:04 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/08 18:04:59 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	space_err(char *input)
{
	int i;

	i = 0;
	while (input[i] == ' ')
			i++;
	if (input[i] == 0)
		return (-1);
	return (0);
}

// int	quotes_error(char *input)
// {
// 	return (0);
// }