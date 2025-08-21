/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:08:19 by tgeler            #+#    #+#             */
/*   Updated: 2025/08/20 21:08:19 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}
int		free_and_rebuild(char **stash, char	*new_stash, int length_new_stash)
{
	int	i;

	i = 0;
	free(*stash);
	*stash = malloc(length_new_stash + 1);
	if (!*stash)
		return (0);
	fill_it(*stash, new_stash, length_new_stash, 0);
	(*stash)[length_new_stash] = '\0';
	free(new_stash);
	return (1);
}
void	fill_it(char *dst, char *src, int length, int j)
{
	int	i;

	i = 0;
	while (i < length)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	return ;
}
char	*divide_the_stash(char *line, char **stash, int i, int length_new_stash)
{
	int		length_line;
	char	*new_stash;

	length_new_stash = 0;
	while ((*stash)[i] != '\n')
		i++;
	length_line = i + 1;
	line = malloc(length_line + 1);
	if (!line)
		return (NULL);
	i++;
	while((*stash)[i] != '\0')
	{
		length_new_stash++;
		i++;
	}
	new_stash = malloc(length_new_stash + 1);
	if(!new_stash)
		return (NULL);
	fill_it(line, *stash, length_line, 0);
	if (length_new_stash != 0)
		fill_it(new_stash, *stash, length_new_stash, length_line);
	free_and_rebuild(&stash, new_stash, length_new_stash);
	line[length_line] = '\0';
	return (line);
}
int	is_there_a_new_line(char *buffer, int bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
