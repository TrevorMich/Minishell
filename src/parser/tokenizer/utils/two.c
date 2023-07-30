/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:27:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:28:03 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	token_add_back(t_token **lst, t_token *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		token_last(*lst)->next = new;
}

t_token	*token_last(t_token *lst)
{
	t_token	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	remove_quotes(char *s)
{
	int	len;

	len = ft_strlen(s);
	if ((len >= 2 && s[0] == '"' && s[len - 1] == '"')
		|| (len >= 2 && s[0] == '\'' && s[len - 1] == '\''))
	{
		ft_memmove(s, s + 1, len - 2);
		s[len - 2] = '\0';
	}
}

void	check_tokens(t_token *token)
{
	t_token	*token_lst;

	token_lst = token;
	while (token_lst)
	{
		printf("string: %s\nquote_type: %d\ntoken_type: %d\n\n",
			token_lst->string,
			token_lst->e_quote_type,
			token_lst->e_token_type
			);
		token_lst = token_lst->next;
	}
}
