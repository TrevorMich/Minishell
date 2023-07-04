/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:55:36 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/03 21:59:56 by ioduwole         ###   ########.fr       */
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
	while (1)
	{
		data->input = readline("Minishell$: "); //Collect input from user
		if (ft_strlen(data->input) > 0)
		{
			add_history(data->input);
			printf("%s\n", data->input);
			// data_handler(data);
			if (ft_strcmp(data->input, "exit") == 0)
				free_all(data);
		}
		else
			free (data->input);
	}
	return (0);
}
