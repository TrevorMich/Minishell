/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:41:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 16:49:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser(t_data *data)
{


	remove_consecutive_quotes(data->input);
	// tokenizer(&data->token_lst, data->input);
	tokenizer(data);
	// check_tokens(data->token_lst);
	expand_token_lst(data);
}