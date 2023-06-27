/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:55:36 by ioduwole          #+#    #+#             */
/*   Updated: 2023/06/27 16:22:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int main(int argc, char **argv, char **envp)
// {
// 	(void)argv;
// 	t_data	*data;
	
// 	if (argc != 1 || !envp)
// 		return (1);
// 	data = ft_calloc(1, sizeof(t_data));
// 	create_env_node(envp);
	
// 	readline("Minishell: ");
// 	rl_replace_line("Macroshell: ", 2);
// 	(void)data;
// 	return (0);
// }

int main() {
    char* input;

    input = readline("Enter your name: ");
    rl_replace_line("New line of text", 1); // Replace the input line with "New line of text" and clear undo history
    rl_redisplay(); // Redisplay the modified line

    printf("You entered: %s\n", input);

    free(input);
    return 0;
}