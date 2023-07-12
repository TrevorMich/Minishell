/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:50:28 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/12 13:49:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redirection_err_s_in(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 1]) + 1;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (print_err("Token error", "<"), -1);
	}
	return (*i);
}

int	redirection_err_s_out(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 1]) + 1;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (print_err("Token error", ">"), -1);
	}
	return (*i);
}

int	redirection_err_d_in(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 2]) + 2;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{		
		return (print_err("Token error","<<"), -1);
	}
	return (*i);
}

int	redirection_err_d_out(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 2]) + 2;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (print_err("Token error",">>"), -1);
	}
	return (*i);
}