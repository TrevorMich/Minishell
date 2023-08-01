/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:30:19 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/31 16:16:11 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_minishell(t_data *data)
{
	if (!ft_strcmp(data->input, "exit"))
		exit_free(data);
	if (input_error(data) == -1)
	{
		g_exit_status = 2;
		return (-1);
	}
	parser(data);
	cmd_init(data);
	get_path(data);
	if (!init_fds(data))
		return (free_exec(data), 0);
	execute(data);
	free_exec(data);
	return (1);
}

void	minishell(t_data *data)
{
	while (1)
	{
		sig_interactive();
		data->input = readline("\033[1;34m""minishell$: ""\033[0m");
		if (!data->input)
		{
			write(1, "exit\n", 5);
			exit_free(data);
			exit(0);
		}
		if (ft_strlen(data->input) > 0)
		{
			add_history(data->input);
			exec_minishell(data);
		}
		else
			free (data->input);
	}
}
