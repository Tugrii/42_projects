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

static char	*check_path_validity(char *path, int mode)
{
	if (access(path, mode) == 0)
		return (path);
	return (NULL);
}

static char	*path_joiner(char *path, char *cmd)
{
	char	*new_path;

	new_path = ft_strjoin(path, cmd);
	return (new_path);
}

char	*path_creater(char **paths, char *cmd)
{
	int		i;
	char	*temp_path;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, 1) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	if (paths)
	{
		while (paths[i] != NULL)
		{
			temp_path = path_joiner(paths[i], cmd);
			if (check_path_validity(temp_path, 1) != NULL)
				return (temp_path);
			else
				free (temp_path);
			i++;
		}
	}
	return (NULL);
}
