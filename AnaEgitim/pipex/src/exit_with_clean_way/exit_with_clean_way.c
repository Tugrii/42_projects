/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_clean_way.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_with_clean_way.h"

static int	exit_with_clean_way1(char **str1, char **str2)
{
	int	i;

	i = 0;
	if (str1)
	{
		while (str1[i])
		{
			free (str1[i]);
			i++;
		}
		free (str1);
	}
	i = 0;
	if (str2)
	{
		while (str2[i])
		{
			free (str2[i]);
			i++;
		}
		free (str2);
	}
	return (1);
}

static int	exit_with_clean_way2(char **str1, char *str2, char *str3)
{
	int	i;

	i = 0;
	if (str1)
	{
		while (str1[i])
		{
			free (str1[i]);
			i++;
		}
		free (str1);
	}
	if (str2)
		free (str2);
	if (str3)
		free (str3);
	return (1);
}

int	clean_and_exit(t_pipex *pipex, int exit_type, char *msg)
{
	exit_with_clean_way1(pipex->splitted_cmd1, pipex->splitted_cmd2);
	exit_with_clean_way2(pipex->paths, pipex->path1, pipex->path2);
	if (msg)
		print_error_exit(msg, exit_type);
	exit(exit_type);
}

void	command_not_found(char *cmd, t_pipex *pipex)
{
	ft_putstr_fd(cmd, 2);
	if (ft_strchr(cmd, '/'))
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
	clean_and_exit(pipex, 127, NULL);
}
