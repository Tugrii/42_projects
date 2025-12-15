/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finder.h"

static char	**double_array_join(char **str, char *to_add_str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] != NULL)
	{
		temp = str[i];
		str[i] = ft_strjoin(str[i], to_add_str);
		free(temp);
		i++;
	}
	return (str);
}

static char	*path_finder_utils(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if ((ft_strnstr(str[i], "PATH=", 5)))
			return (str[i]);
		i++;
	}
	return (NULL);
}

char	**path_finder(char **str)
{
	char	*non_splitted_path;
	char	**splitted_path;

	non_splitted_path = path_finder_utils(str);
	if (!non_splitted_path)
		return (NULL);
	non_splitted_path += 5;
	splitted_path = ft_split(non_splitted_path, ':');
	double_array_join(splitted_path, "/");
	return (splitted_path);
}

void	split_the_commands(t_pipex *pipex)
{
	pipex->splitted_cmd1 = ft_split(pipex->argv[0], ' ');
	pipex->splitted_cmd2 = ft_split(pipex->argv[1], ' ');
	if (!pipex->splitted_cmd1)
		print_error_int("Malloc Error! at splitting cmd1\n");
	if (!pipex->splitted_cmd2)
		print_error_int("Malloc Error! at splitting cmd2\n");
	if (!pipex->splitted_cmd1 || !pipex->splitted_cmd2)
		clean_and_exit(pipex, 1, "Error! about malloc! at spliting cmds:");
	return ;
}
