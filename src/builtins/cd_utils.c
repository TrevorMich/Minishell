/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:57:45 by ioduwole          #+#    #+#             */
/*   Updated: 2023/07/10 19:16:16 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_oldpwd(t_data *data)
{
	char	*old_pwd;

	old_pwd = get_current_dir();
	if (old_pwd)
	{
		update_env_value(data->env, "OLDPWD", old_pwd);
		free(old_pwd);
	}
}

void	update_env_value(t_env *list, char *var, char *new_value)
{
	t_env	*ptr;

	ptr = list;
	while (ptr)
	{
		if (!ft_strcmp(ptr->var, var))
		{
			free(ptr->value);
			ptr->value = ft_strdup(new_value);
			return ;
		}
		ptr = ptr->next;
	}
}

char	*get_current_dir(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("getcwd");
		return (NULL);
	}
	return (pwd);
}
