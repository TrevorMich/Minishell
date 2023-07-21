/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:55:36 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/21 20:30:52 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"









int	main(int argc, char **argv, char **envp)
{
	t_data	*data; //pointer to data struct

	(void) argv;
	print_welcome(argc, argv);
	// if (argc != 1)
	// 	return (1);
data = ft_calloc(1, sizeof(t_data)); // Allocated memory for data struct
	create_env_list(data, envp); //check israel_README
	// get_path(data);
	minishell(data);
	return (0);
}
