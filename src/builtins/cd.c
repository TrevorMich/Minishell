/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:19:47 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/29 22:11:21 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd(t_data *data, char **str)
{
	g_exit_status = 0;
	update_oldpwd(data);
	if (array_length(str) == 1)
		cd_to_home(data);
	else if (chdir(str[1]))
	{
		printf("minishell: cd: %s: %s\n", str[1], strerror(errno));
		g_exit_status = 1;
		return ;
	}
	update_pwd(data);
}

void	cd_to_home(t_data *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp && !(!ft_strcmp(tmp->var, "HOME")))
		tmp = tmp->next;
	if (!tmp || chdir(tmp->value))
	{
		if (!tmp)
			printf("minishell: cd: HOME not set\n");
		else
			printf("minishell: cd: %s\n", tmp->value);
		g_exit_status = 1;
	}	
	else
		g_exit_status = 0;
}

void	update_dir(t_data *data)
{
	char	*new_dir;

	new_dir = get_current_dir();
	if (new_dir)
	{
		update_env_value(data->env, "PWD", new_dir);
		free(new_dir);
	}
}

void	update_pwd(t_data *data)
{
	char	*new_pwd;

	new_pwd = get_current_dir();
	if (new_pwd)
	{
		update_env_value(data->env, "PWD", new_pwd);
		free(new_pwd);
	}
}
