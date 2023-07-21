/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:40:46 by doduwole          #+#    #+#             */
/*   Updated: 2023/07/21 11:44:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

// "$@"	is an array-like construct of all positional parameters, {$1, $2, $3 ...}.
// "$*"	is the IFS expansion of all positional parameters, $1 $2 $3 ....
// $#	is the number of positional parameters.
// $-	current options set for the shell.
// $$	pid of the current shell (not subshell).
// $_	most recent parameter (or the abs path of the command to start the current shell immediately after startup).
// $IFS	is the (input) field separator.
// $?	is the most recent foreground pipeline exit status.
// $!	is the PID of the most recent background command.
// $0	is the name of the shell or shell script.

void	process_expansion(char *token, t_data *data, t_idx *idx, char **exp)
{
	if (token[idx->i] == '$')
	{
		if (token[idx->i + 1] == '?')
			handle_exit_status(exp, idx); // to find exit status of last command
		else if (token[idx->i + 1] == '$')
			handle_single_dollar(exp, idx); // use to find PID of current shell script
		else if (ft_isalnum(token[idx->i + 1]) || token[idx->i + 1] == '_')
			handle_env_var(exp, idx, token, data);
		else
			copy_token_char(exp, idx, token[idx->i++]);
	}
	else
		copy_token_char(exp, idx, token[idx->i++]);
}


char	*expand_token(char *token, t_data *data)
{
	char	*exp;
	t_idx	idx;

	exp = malloc(MAX_TOKEN_SIZE);
	if (!token)
	{
		print_err("Malloc failed in expand_token func","");
		g_exit_status = 13;
		return (NULL);
	}
	idx.i = 0;
	idx.j = 0;
	while (token[idx.i] != '\0')
		process_expansion(token, data, &idx, &exp);
	exp[idx.j] = '\0';
	return (exp);
}
