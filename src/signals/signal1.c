/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:43:27 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/26 20:55:12 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ignore_ctrl_bslash(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	ctrl_c_ctrl_bslash_noninteractive(int sig)
{
	if (sig == SIGQUIT)
	{
		g_exit_status = 128 + sig;
		write(1, "quit\n", 5);
		rl_on_new_line();
	}
	else if (sig == SIGINT)
	{
		g_exit_status = 128 + sig;
		write(1, "\n", 1);
		rl_on_new_line();
	}
}

void	sig_noninteractive(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &ctrl_c_ctrl_bslash_noninteractive;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
