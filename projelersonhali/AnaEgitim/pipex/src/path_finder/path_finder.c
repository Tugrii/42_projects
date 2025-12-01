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

char	**double_array_join(char **str, char *to_add_str)
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

char	*path_finder_utils(char **str)
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
		return (print_error_char("PATH Could'nt found!\n"));
	non_splitted_path += 5;
	splitted_path = ft_split(non_splitted_path, ':');
	double_array_join(splitted_path, "/");
	return (splitted_path);
}
