/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:21:49 by tgeler            #+#    #+#             */
/*   Updated: 2025/08/20 17:21:49 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	make_malloc_for_each_stash(char **stash, int total_length , int bytes_read)
{
	if (!*stash)
		total_length = bytes_read;
	else
		total_length = ft_strlen(*stash) + bytes_read;
	*stash = malloc(total_length + 1);
	if (!*stash)
		return (0);
	return (total_length);
}
int	add_to_stash(char **stash, char *buffer, int index, int bytes_read)
{
	char	*ptr;
	int		total_length;
	int		length_old_stash;
	int		j;

	j = 0;
	length_old_stash = 0;
	ptr = *stash;
	total_length = make_malloc_for_each_stash(*stash, total_length, bytes_read);
	(*stash)[total_length] = '\0';
	length_old_stash = ft_strlen(ptr);
	while (length_old_stash--)
		(*stash)[length_old_stash] = ptr[length_old_stash];
	while (j < bytes_read)
	{
		(*stash)[index] = buffer[j];
		index++;
		j++;
	}
	free (ptr);
	return (j);
}
int	fill_buffer(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	return (bytes_read);
}
char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	static char		*stash = NULL;
	int				index;
	char			*line;
	int				bytes_read;

	bytes_read = 1;
	index = 0;
	line = NULL;
	if (stash != NULL)
		index = ft_strlen(stash);
	while (bytes_read != 0)
	{
		bytes_read = fill_buffer(fd, buffer);
		index += add_to_stash(&stash, buffer, index, bytes_read);
		if (is_there_a_new_line(buffer, bytes_read) == 1)
		{
			line = divide_the_stash(line, &stash, 0, 0);
			break ;
		}
	}
	return (line);
}
