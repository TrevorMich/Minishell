/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:03:55 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/09 14:38:14 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	isbuiltin(t_cmdgroup *group)
{
	char	**str;

	if (!group || !group->cmd[0])
		return (0);
	str = group->cmd;
	if (!ft_strncmp(str[0], "cd", 2) && ft_strlen(str[0]) == 2)
		return (1);
	if (!ft_strncmp(str[0], "export", 6) && ft_strlen(str[0]) == 6)
		return (1);
	if (!ft_strncmp(str[0], "echo", 4) && ft_strlen(str[0]) == 4)
		return (1);
	if (!ft_strncmp(str[0], "pwd", 3) && ft_strlen(str[0]) == 3)
		return (1);
	if (!ft_strncmp(str[0], "env", 3) && ft_strlen(str[0]) == 3)
		return (1);
	if (!ft_strncmp(str[0], "unset", 5) && ft_strlen(str[0]) == 5)
		return (1);
	return (0);
}
