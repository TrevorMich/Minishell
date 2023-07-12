/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:15:16 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/12 10:44:48 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

void print_err(char *err_msg, char *str)
{
	if (str[0] == ' ')
	{
		printf("\033[0;31m""Error:""\033[3m""\033[2;37m"" %s\n""\033[0m", err_msg);
		return;
	}
	printf("\033[0;31m""Error:""\033[3m""\033[2;37m"" %s: '%s'\n""\033[0m", err_msg, str);
}
