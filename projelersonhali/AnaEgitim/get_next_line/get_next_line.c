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

/* char	*make_malloc_and_fill(char **line, char **stash, int length_to_fill)
{
	printf("%s","evreka");
	*line = malloc(length_to_fill + 1);
	if (!*line)
		return (NULL);
	fill_it(*line, *stash, length_to_fill, 0);
	(*line)[length_to_fill] = '\0';
	free(*stash);
	*stash = NULL;
	return (*line);
} */

int	make_malloc_for_each_stash(char **stash, int bytes_read)
{
	int	total_length;

	total_length = 0;

	if (!*stash)
		total_length = bytes_read;
	else
		total_length = ft_strlen(*stash) + bytes_read;
	*stash = malloc(total_length + 1);
	if (!*stash)
		return (0);
	(*stash)[total_length] = '\0';
	return (total_length);
}

int	add_to_stash(char **stash, char *buffer, int index, int bytes_read)
{
	char	*ptr;
	int		length_old_stash;
	int		j;

	j = 0;
	length_old_stash = 0;
	ptr = *stash;
	make_malloc_for_each_stash(stash, bytes_read);
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

	 printf("%s","\n");
	printf("%d.CAGRI :",i);
	printf("%s","\n");
	i++;
	index = 0;
	line = NULL;
	if (fd < 0)
		return (line);
	if (stash)
		index = ft_strlen(stash);
	while (bytes_read != 0)
	{
		bytes_read = *(int *)fill_refill_buffer(fd, &buffer, 'i');
		if (bytes_read != 0)
			index += add_to_stash(&stash, buffer, index, bytes_read);
		free((char *)fill_refill_buffer(fd, &buffer, 'p'));
	}
	if (stash)
		return (divide_the_stash(line, &stash));
	/*else
		return (make_malloc_and_fill(&line, &stash, ft_strlen(stash))); */
	return (line);
}
