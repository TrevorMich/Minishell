/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:41:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/14 16:45:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser(t_data *data)
{
	remove_consecutive_quotes(data->input);
	// tokenizer(&data->token_lst, data->input);
	// expand_token_lst(data);
}