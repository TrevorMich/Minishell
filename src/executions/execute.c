/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:35:41 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/30 07:52:26 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_cmds(t_data *data, t_cmdgroup *group)
{
	char	**str;

	if (group->infile == -1 || group->outfile == -1)
		return ;
	str = group->cmd;
	if (!ft_strcmp(str[0], "echo"))
		do_echo(str);
	if (!ft_strcmp(str[0], "cd"))
		cd(data, str);
	if (!ft_strcmp(str[0], "pwd"))
		pwd();
	if (!ft_strcmp(str[0], "export"))
		do_export(data, str);
	if (!ft_strcmp(str[0], "unset"))
		do_unset(data, str);
	if (!ft_strcmp(str[0], "env"))
		do_env(data, str);
}

void	handle_out(t_cmdgroup *group)
{
	if (!the_builtins(group))
		close(group->pipes[0]);
	if (group->next && group->outfile == 1
		&& (access(group->cmd[0], X_OK) == 0 || the_builtins(group)))
		dup2(group->pipes[1], STDOUT_FILENO);
	if (group->outfile > 1)
	{
		dup2(group->outfile, STDOUT_FILENO);
		close(group->outfile);
	}
	close(group->pipes[1]);
}

void	handle_in(t_cmdgroup *group)
{
	if (group->prev && group->prev->outfile == 1
		&& group->infile == 0 && group->prev->cmd
		&& !the_builtins(group))
	{
		close(group->prev->pipes[1]);
		dup2(group->prev->pipes[0], STDIN_FILENO);
		close(group->prev->pipes[0]);
	}
	if (group->infile > 0)
		dup2(group->infile, STDIN_FILENO);
}

void	handler(t_cmdgroup *group)
{
	if (group->infile == -1 || group->outfile == -1
		|| !group->cmd || !group->cmd[0])
	{
		if (!the_builtins(group))
			exit(1);
		return ;
	}
	handle_out(group);
	handle_in(group);
}

void	execute(t_data *data)
{
	t_cmdgroup	*group;
	int			stdin;
	int			stdout;

	sig_noninteractive();
	group = data->cmdgroup;
	while (group)
	{
		if (the_builtins(group))
		{
			stdin = dup(STDIN_FILENO);
			stdout = dup(STDOUT_FILENO);
			handler(group);
			exec_cmds(data, group);
		}
		else
			child_process(group);
		if (the_builtins(group))
			ft_default(stdin, stdout);
		else
			close_pipes(group);
		group = group->next;
	}
	parent_wait(data->cmdgroup);
}
