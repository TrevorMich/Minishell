/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:50:28 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/12 15:26:09 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redir_type_err(char *s, int *i, char *redir_type, int skip_num)
{
	*i += skip_spaces(&s[*i + skip_num]) + skip_num;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (print_err("Token error", redir_type), -1);
	}
	return (*i);
}
