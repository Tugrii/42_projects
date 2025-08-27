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

	new_stash = NULL;
	int	last_datas_length;
	int	total_length;

	last_datas_length = ft_strlen(*stash);
	total_length = last_datas_length + bytes_read;
	new_stash = malloc(total_length + 1);
	if (!new_stash)
		return (NULL);
	(new_stash)[total_length] = '\0';
	fill_it(new_stash, *stash, last_datas_length, 0);
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
	return (j);
}

void	*fill_refill_buffer(int fd, char **buffer, char mode)
{
	static int	bytes_read;
	static char	*ptr = NULL;

	if (mode == 'p')
		return ((void *)ptr);
	if (mode == 'i')
	{
		*buffer = malloc(BUFFER_SIZE + 1);
		if (!*buffer)
			return (0);
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[BUFFER_SIZE] = '\0';
		ptr = *buffer;
		return ((void *)&bytes_read);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*stash = NULL;
	int				index;
	char			*line;
	static int		bytes_read = 1;
	static int 		i = 1;

	/* printf("%d.CAGRI :",i);
	printf("%s","\n"); */
	i++;
	index = 0;
	line = NULL;
	if (fd < 0)
		return (line);
	if (stash)
		index = ft_strlen(stash);
	while (bytes_read > 0)
	{
		bytes_read = *(int *)fill_refill_buffer(fd, &buffer, 'i');
		if (bytes_read > 0)
			index += add_to_stash(&stash, buffer, index, bytes_read);
		free((char *)fill_refill_buffer(fd, &buffer, 'p'));
	}
	/* if (!stash)
		printf("%s","stashbos"); */
	if (stash && is_there_a_new_line(stash, ft_strlen(stash), 0) != 0)
		return (divide_the_stash(line, &stash));
	return (last_stash_controls(&stash, &line));
}
