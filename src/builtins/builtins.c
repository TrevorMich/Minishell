/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:03:55 by ioduwole          #+#    #+#             */
/*   Updated: 2023/08/01 09:14:15 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	the_builtins(t_cmdgroup *group)
{
	char	**str;

	if (!group->cmd || !group->cmd[0])
		return (0);
	str = group->cmd;
	if (!ft_strcmp(str[0], "cd"))
		return (1);
	if (!ft_strcmp(str[0], "export"))
		return (1);
	if (!ft_strcmp(str[0], "echo"))
		return (1);
	if (!ft_strcmp(str[0], "pwd"))
		return (1);
	if (!ft_strcmp(str[0], "env"))
		return (1);
	if (!ft_strcmp(str[0], "unset"))
		return (1);
	return (0);
}
