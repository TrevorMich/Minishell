// #include "minishell.h"

// int main(int argc, char **argv, char **envp)
// {
// 	(void)argv;
// 	char	*input;
// 	char	*tmp_path;
// 	char	**path;
// 	char    **tmp;
// 	char	*tmp1;
// 	int 	i;

// 	i = 0;
// 	if (argc != 1 || !envp)
// 		return (printf("Run just the minishell executable!\n"), 1);
// 	while (envp[i])
// 	{
// 		if (ft_strncmp("PATH=", envp[i], 5) == 0)
// 			tmp_path = envp[i];
// 		i++;
// 	}
// 	tmp = ft_split(tmp_path, ':');
// 	i = 0;
// 	while(1)
// 	{
// 		input = readline("Minishell$: ");

// 		add_history(input);
// 		path = ft_split(input, ' ');
// 		while (tmp[i])
// 		{
// 			if (tmp[i][ft_strlen(tmp[i]) - 1] != '/')
// 				tmp1 = ft_strjoin2(tmp[i], path[0]);
// 			else
// 				tmp1 = ft_strjoin(tmp[i], path[0]);
// 			if (access(tmp1, X_OK) == 0)
// 			{
// 				free(path[0]);
// 				path[0] = ft_strdup(tmp1);
// 				free(tmp1);
// 				break ;
// 			}
// 			i++;
// 		}
// 		int pid = fork();
// 		if (pid == -1)
// 			return 1;
// 		if (pid == 0)
// 			execve(path[0], path, NULL);
// 		else
// 			wait(NULL);
// 		free(input);
// 		clear_string(path);

// 	}
// 	return (0);
// }

// void	clear_string(char **str)
// {
// 	int	i;

// 	if (!str)
// 		return ;
// 	i = 0;
// 	while (str[i])
// 	{
// 		free (str[i]);
// 		i++;
// 	}
// 	free (str);
// }
