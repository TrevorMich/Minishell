/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:28:27 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/14 16:42:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief test commands
// </dev/stdin tr -d 'e' | ls
// cat | uname -a
// echo "$(cat Makefile)"
// ls > file
// cat < ls
// exec 5<> file
// ps -ef | grep systemd | awk '{ print $2 }'
// ls * | sort > file
// ls -la | grep a | tr 'a-z' 'A-Z'
// 
// cat << EOF > file
// cat file
// rm file
// 
// ls | rev > file
// cat file
// rev file | cat
// rm file

int	input_error(t_data *data)
{
	char	*input;

	input = data->input;
	if ((ft_strlen(input) == 0)
		|| (space_err(input) == -1)
		|| (quote_err(input) == -1)
		|| (pipe_err(input) == -1)
		|| (special_char_err(input) == -1)
		|| (redirection_err(input) == -1))
		return (-1);
	return (0);
}
