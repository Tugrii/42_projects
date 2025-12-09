/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
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
		return (print_error_p_char("PATH Could'nt found!\n"));
	non_splitted_path += 5;
	splitted_path = ft_split(non_splitted_path, ':');
	double_array_join(splitted_path, "/");
	return (splitted_path);
}

int	split_the_commands(char ***splitted_cmd1, char *cmd1,
		char ***splitted_cmd2, char *cmd2)
{
	*splitted_cmd1 = ft_split(cmd1, ' ');
	*splitted_cmd2 = ft_split(cmd2, ' ');
	if (!*splitted_cmd1 || !*splitted_cmd2)
		return (print_error_int("Error! About spliting the cmds!\n"));
	return (1);
}
