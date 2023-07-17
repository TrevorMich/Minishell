/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:45:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/17 08:45:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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