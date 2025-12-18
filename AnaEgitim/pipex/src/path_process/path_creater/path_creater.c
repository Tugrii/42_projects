/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_creater.h"

static char	*check_path_validity(t_pipex *pipex, char *path,
			char *cmd, char mode)
{
	char	*temp;

	temp = NULL;
	if (mode == '0')
	{
		temp = ft_strdup(cmd);
		if (!temp)
			clean_and_exit(pipex, 1, "Error! about malloc for exact path!:");
		if (access(cmd, 1) == 0)
			return (temp);
	}
	else if (mode == '1')
	{
		if (access(path, 1) == 0)
			return (path);
	}
	free (temp);
	return (NULL);
}

static char	*path_joiner(t_pipex *pipex, char *path, char *cmd)
{
	char	*new_path;

	new_path = ft_strjoin(path, cmd);
	if (!new_path)
		clean_and_exit(pipex, 1, "Error! about malloc for path join!:");
	return (new_path);
}

char	*path_creater(t_pipex *pipex, char **paths, char *cmd)
{
	int		i;
	char	*temp_path;

	i = 0;
	temp_path = NULL;
	if (cmd)
	{
		if (ft_strchr(cmd, '/'))
			return (check_path_validity(pipex, temp_path, cmd, '0'));
		else if (paths)
		{
			while (paths[i] != NULL)
			{
				temp_path = path_joiner(pipex, paths[i], cmd);
				if (check_path_validity(pipex, temp_path, cmd, '1') != NULL)
					return (temp_path);
				else
					free (temp_path);
				i++;
			}
		}
	}
	return (NULL);
}
