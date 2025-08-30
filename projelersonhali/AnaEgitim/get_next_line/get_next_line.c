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

char	*tr_old_to_new(char **stash, int bytes_read)
{
	char	*new_stash;
	int	total_length;

	total_length = ft_strlen(*stash) + bytes_read;
	new_stash = malloc(total_length + 1);
	if (!new_stash)
		return (NULL);
	new_stash[total_length] = '\0';
	fill_it(new_stash, *stash, 0, 0);
	free (*stash);
	return (new_stash);
}
int	add_to_stash(char **stash, char *buffer, int index, int bytes_read)
{
	int			j;
	
	j = 0;
	if (!*stash)
	{
		*stash = malloc(bytes_read + 1);
		if (!*stash)
			return (0);
		(*stash)[bytes_read] = '\0';
	}
	else
		*stash = tr_old_to_new(stash, bytes_read);
	while (j < bytes_read)
	{
		(*stash)[index] = buffer[j];
		index++;
		j++;
	}
	return (index);
}
int	fill_buffer(char **stash, char **line, int index, int fd)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	//printf("%s","fill_buffer");
	while (is_there_a_new_line(*stash, ft_strlen(*stash), 0) == 0 || is_there_a_new_line(*stash, ft_strlen(*stash), 0) == 1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		buffer[BUFFER_SIZE] = '\0';
		if (bytes_read > 0)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free (buffer);
			return (bytes_read);
		}
		index = add_to_stash(stash, buffer, index, bytes_read);
		//printf("%s","stash_dolduruldu");
		free (buffer);
	}
	if (is_there_a_new_line(*stash, ft_strlen(*stash), 0) != 0)
		*line = divide_the_stash(line, stash);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	int				index;
	char			*line;
	static int		bytes_read = 1;

	index = 0;
	line = NULL;
	if (fd < 0)
		return (line);
	if (stash)
		index = ft_strlen(stash);
	if (bytes_read > 0)
		bytes_read = fill_buffer(&stash, &line, index, fd);
	if (is_there_a_new_line(stash, ft_strlen(stash), 0) == 1)
		return (divide_the_stash(&line, &stash));
	return (last_stash_controls(&stash, &line, bytes_read));
}
