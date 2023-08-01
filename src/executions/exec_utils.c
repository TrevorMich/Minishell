/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:10:56 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/27 01:20:30 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	child_process(t_cmdgroup *group)
{
	if (!group->cmd)
		return ;
	group->pid = fork();
	if (group->pid == 0)
	{
		handler(group);
		if (execve(group->cmd[0], group->cmd, NULL) == -1)
			printf("minishell: %s: command not found\n", group->cmd[0]);
		exit(127);
	}
}

void	ft_default(int stdin, int stdout)
{
	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
	close(stdin);
	close(stdout);
}

void	close_pipes(t_cmdgroup *group)
{
	if (group->prev)
	{
		close(group->prev->pipes[0]);
		close(group->prev->pipes[1]);
	}
}

void	parent_wait(t_cmdgroup *group)
{
	t_cmdgroup	*tmp;

	tmp = group;
	while (tmp)
	{
		if (!the_builtins(tmp))
			waitpid(tmp->pid, &g_exit_status, 0);
		tmp = tmp->next;
	}
}
