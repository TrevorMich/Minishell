/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:28:27 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/10 11:45:57 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	input_error(t_data *data)
{
	char	*input;

	input = data->input;
	if (ft_strlen(input) == 0)
		return (-1);
	else if (space_err(input) == -1)
		return (-1);
	// else if (quotes_err(input) == -1)
	// 	return (-1);
	return (0);
}
