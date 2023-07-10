/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:55:36 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/10 20:59:33 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data; //pointer to data struct
	(void) argv;
	if (argc != 1)
		return (1);
	data = ft_calloc(1, sizeof(t_data)); //Allocated memory for data struct
	create_env_list(data, envp); //check israel_README
	// get_path(data);
	minishell(data);
	return (0);
}

void	minishell(t_data *data)
{
	t_cmdgroup *group;
	group = ft_calloc(1, sizeof(t_cmdgroup));
	while (1)
	{
		data->input = readline("Minishell$: "); //Collect input from user
		if (!data->input)
		{
			write(1, "exit\n", 5);
			free_all(data);
			exit(0);
		}
		if (ft_strlen(data->input) > 0)
		{
			group->cmd = ft_split(data->input, ' ');
			add_history(data->input);
			// exec_minishell(data);
			if (!ft_strcmp(data->input, "pwd"))
				pwd();
			if (!ft_strcmp(group->cmd[0], "env"))
				do_env(data, group->cmd);
			if (!ft_strcmp(group->cmd[0], "cd"))
			{
				if (array_length(group->cmd) == 1)
					cd_to_home(data);
				else if(array_length(group->cmd) > 1)
					cd(data, &group->cmd[1]);
			}
			// free(data->input);
		}
		else
			free (data->input);
	}
}

int	exec_minishell(t_data *data)
{
	if (ft_strncmp(data->input, "exit", 4) && ft_strlen(data->input) == 4)
		free_all(data);
	if (input_error(data) == -1)
		return (-1);

	return (0);
}
