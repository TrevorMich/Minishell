/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:55:36 by ioduwole          #+#    #+#             */
/*   Updated: 2023/06/22 11:37:06 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	while(1)
	{
		char *line;
		int len = 0;
		line = readline("Minishell$: ");
		rl_on_new_line();
		len = strlen(line);
		if (!line)
		{
			printf("exit\n");
			exit(1);
		}
		if (strlen(line) > 0)
			add_history(line);
		else
			return (2);

		printf("%s\n", line);
		// rl_clear_history();
		free(line);
	}
	
	return (0);
}
