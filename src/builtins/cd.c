/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:19:47 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/09 14:33:37 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_to_home(t_data *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp && !(!ft_strncmp(tmp->var, "HOME", 4) && 
			ft_strlen(tmp->var) == 4))
		tmp = tmp->next;
	if (!tmp || chdir(tmp->value))
	{
		if (!tmp)
			printf("minishell: cd: HOME not set\n");
		else
			printf("minishell: cd: %s\n", tmp->value);
	}	
	update_dir(data);
}

void	cd(t_data *data, char **str)
{
	update_oldpwd(data);
	if (array_length(str) == 1)
		cd_to_home(data);
}

void	update_dir(t_data *data)
{
	char *new_dir;

	new_dir = get_current_dir();
	if (new_dir)
	{
		update_env_value(data->env, "PWD", new_dir);
		free(new_dir);
	}
}
