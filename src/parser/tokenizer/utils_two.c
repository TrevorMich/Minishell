/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:04:12 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/18 16:08:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void check_tokens(t_token *token)
{
	t_token *token_lst;

	token_lst = token;
	while (token_lst)
	{
		printf("%s %d %d\n",token_lst->string, token_lst->e_quote_type, token_lst->e_token_type);
		token_lst = token_lst->next;
	}
}