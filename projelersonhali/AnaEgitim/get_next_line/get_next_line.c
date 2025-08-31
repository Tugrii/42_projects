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

void	fill_new_stash(char *new_stash, char *stash, int index, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		new_stash[i] = stash[index];
		index++;
		i++;
	}
	return ;
}
char *build_new_malloc_for_stash(char **stash, int bytes_read)
{
	int		length;
	char	*new_stash;

	length = ft_strlen(*stash) + bytes_read;
	new_stash = malloc(length + 1);
	if (!new_stash)
		return (NULL);
	new_stash[length] = '\0';
	fill_it(new_stash, *stash, 0, 0);
	free (*stash);
	return (new_stash);
}

void	add_to_stash(char **stash, char *buffer, int bytes_read)
{
	char	*new_stash;
	int		length;

	length = ft_strlen(*stash) + bytes_read;
	if (!*stash)
	{
		*stash = malloc(length + 1);
		if (!*stash)
			return ;
		(*stash)[length] = '\0';
		fill_it(*stash, buffer, 0, 0);
		return ;
	}
	else
		*stash = build_new_malloc_for_stash(stash, bytes_read);
	fill_it(new_stash, buffer, 0, length);
	return ;
}

int	fill_buffer(char **stash, char **line, int fd)
{
	int			bytes_read;
	char		*buffer;

	bytes_read = 1;
	while (is_there_a_new_line(*stash, ft_strlen(*stash), 0, '1') == 0)
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
		add_to_stash(stash, buffer, bytes_read);
		free (buffer);
	}
	if (is_there_a_new_line(*stash, ft_strlen(*stash), 0, '1') != 0)
		*line = divide_the_stash(line, stash);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;
	static int		bytes_read = 1;
	static int		i = 1;
	line = NULL;
	if (fd < 0)
		return (line);
	if (i == 3 && !*stash)
		printf("%s","EVET");
	if (ft_strlen(stash) == 1)
	{
		line = last_stash_controls(&stash, &line);
		stash = NULL;
		return (line);
	}
	if (bytes_read > 0)
		bytes_read = fill_buffer(&stash, &line,fd);
	i++;
	return (line);
}
