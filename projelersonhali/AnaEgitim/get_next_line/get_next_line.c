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

int	add_to_stash(char *stash, char *buffer, int i, int counter)
{
	int		j;

	i = 0;
	j = 0;
	if (stash == NULL)
		i = 0;
	stash = malloc(BUFFER_SIZE * counter);
	while (j < BUFFER_SIZE)
	{
		stash[i] = buffer[j];
		i++;
		j++;
	}
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
	int				counter;

	counter = 1;
	index = 0;
	if (stash != NULL)
		index = ft_strlen(stash);
	while (fill_buffer(fd, buffer) != 0)
	{
		index += add_to_stash(stash, buffer, index, counter);
		if (is_there_a_new_line(buffer) == 1)
		{
			line = divide_the_stash(line, &stash, 0);
			break ;
		}
		counter++;
	}
	return (line);
}
