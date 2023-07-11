/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:28:27 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/10 20:01:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// [🔴] check if str is only spaces
// [🔴] check mismatched quotations
// [🔴] check pipe related error
// [🔴] check unsupported special char
// [🔴] check re-directions positioning
// [🔴] check unsupported special char
// [🔴] check unsupported special char

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
