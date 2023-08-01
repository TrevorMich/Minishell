/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:07:02 by ioduwole          #+#    #+#             */
/*   Updated: 2023/08/01 09:27:07 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	insert_end_outs(t_token *token, t_cmdgroup *group)
{
	t_outs	*new;
	t_outs	*tmp;

	new = ft_calloc(sizeof(t_outs), 1);
	new->str = ft_strdup(token->string);
	new->append = 0;
	if (token->e_token_type == APP_RDR)
		new->append = 1;
	new->next = NULL;
	if (group->outs == NULL)
	{
		group->outs = new;
		return ;
	}
	tmp = group->outs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	insert_end_ins(t_token *token, t_cmdgroup *group)
{
	t_ins	*new;
	t_ins	*tmp;

	new = ft_calloc(sizeof(t_ins), 1);
	new->str = ft_strdup(token->string);
	new->heredoc = 0;
	if (token->e_token_type == HERE_DOC)
		new->heredoc = 1;
	new->next = NULL;
	if (group->ins == NULL)
	{
		group->ins = new;
		return ;
	}
	tmp = group->ins;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_token	*add_group(t_data *data, t_token *token)
{
	t_token		*tok;
	t_cmdgroup	*group;
	t_cmdgroup	*tmp;

	tok = token;
	group = ft_calloc(sizeof(t_cmdgroup), 1);
	while (tok && tok->e_token_type != PIPE)
	{
		if (tok->e_token_type == WORD)
			group->str = ft_strjoin2(group->str, tok->string, '\n');
		else if (tok->e_token_type == IN_RDR || tok->e_token_type == HERE_DOC)
			insert_end_ins(tok, group);
		else if (tok->e_token_type == OUT_RDR || tok->e_token_type == APP_RDR)
			insert_end_outs(tok, group);
		tok = tok->next;
	}
	group->cmd = ft_split(group->str, '\n');
	if (data->cmdgroup == NULL)
		return ((data->cmdgroup = group), tok);
	tmp = data->cmdgroup;
	while (tmp->next)
		tmp = tmp->next;
	group->prev = tmp;
	tmp->next = group;
	return (tok);
}

void	cmd_init(t_data *data)
{
	t_token	*token;

	token = data->token_lst;
	while (token)
	{
		token = add_group(data, token);
		if (token)
			token = token->next;
	}
}
