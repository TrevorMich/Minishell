/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:17:27 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:09:33 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	here_doc2(char *delimeter)
{
	char	*str;
	int		fd;

	sig_heredoc();
	fd = open("here_doc.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	str = readline(">");
	while (ft_strcmp(str, delimeter))
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline(">");
	}
	free(str);
	close(fd);
	exit(1);
}

int	here_doc(char *delimeter)
{
	int	pid;
	int	check_exit;

	check_exit = 1;
	pid = fork();
	if (pid == 0)
		here_doc2(delimeter);
	else
	{
		sig_parent_heredoc();
		waitpid(pid, &check_exit, 0);
		if (WIFEXITED(check_exit))
			return (1);
	}
	return (0);
}

int	handle_infiles(t_cmdgroup *group)
{
	t_ins	*ins;

	ins = group->ins;
	while (ins)
	{
		if (ins->heredoc)
		{
			if (!here_doc(ins->str))
				return (0);
			group->infile = open("here_doc.txt", O_RDONLY);
		}
		else
			group->infile = open(ins->str, O_RDONLY);
		if (group->infile == -1)
		{
			printf("minishell: %s: %s\n", ins->str, strerror(errno));
			g_exit_status = 1;
			return (1);
		}
		ins = ins->next;
	}
	return (1);
}

void	handle_outfiles(t_cmdgroup *group)
{
	t_outs	*outs;

	outs = group->outs;
	while (outs)
	{
		if (outs->append)
			group->outfile = open(outs->str, O_WRONLY | O_CREAT | O_APPEND,
					0777);
		else
			group->outfile = open(outs->str, O_WRONLY | O_CREAT | O_TRUNC,
					0777);
		if (group->outfile == -1)
		{
			printf("minishell: %s: %s\n", outs->str, strerror(errno));
			g_exit_status = 1;
			return ;
		}
		outs = outs->next;
	}
}

int	init_fds(t_data *data)
{
	t_cmdgroup	*group;

	group = data->cmdgroup;
	while (group)
	{
		group->outfile = 1;
		if (group->ins)
			if (!handle_infiles(group))
				return (0);
		if (group->outs)
			handle_outfiles(group);
		pipe(group->pipes);
		group = group->next;
	}
	return (1);
}
