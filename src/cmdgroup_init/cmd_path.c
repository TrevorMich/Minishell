/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:17:18 by ioduwole          #+#    #+#             */
/*   Updated: 2023/08/01 09:36:48 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_path(t_data *data)
{
	t_env			*env;
	char			**path;
	t_cmdgroup		*group;

	group = data->cmdgroup;
	path = NULL;
	env = find_path(data);
	if (!env)
		return ;
	path = ft_split(env->value, ':');
	while (group)
	{
		add_path(group, path);
		group = group->next;
	}
	clear(path);
}

t_env	*find_path(t_data *data)
{
	t_env	*env;

	env = data->env;
	while (env && !(!ft_strcmp(env->var, "PATH")))
		env = env->next;
	return (env);
}

void	add_path(t_cmdgroup *group, char **path)
{
	int		i;
	char	**tmp_path;

	i = 0;
	if (!group->cmd || !group->cmd[0] || !access(group->cmd[0], X_OK)
		|| the_builtins(group))
		return ;
	tmp_path = ft_calloc(array_length(path) + 1, sizeof(char *));
	while (path[i])
	{
		if (path[i][ft_strlen(path[i]) - 1] != '/')
			tmp_path[i] = ft_strjoin2(path[i], group->cmd[0], '/');
		else
			tmp_path[i] = ft_strjoin(path[i], group->cmd[0]);
		if (access(tmp_path[i], X_OK) == 0)
		{
			free(group->cmd[0]);
			group->cmd[0] = ft_strdup(tmp_path[i]);
		}
		i++;
	}
	clear(tmp_path);
}
