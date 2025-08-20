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

int	add_to_stash(char *stash, char *buffer, int BUFFER_SIZE, int i)
{
	int		j;

	j = 0;
	if (stash == NULL)
		i = 0;
	while (j < BUFFER_SIZE)
	{
		stash[i] = buffer[j];
		i++;
		j++;
	}
	return (j);
}
int	fill_buffer(int fd, int BUFFER_SIZE, char *buffer)
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

	index = 0;
	while (fill_buffer(fd, BUFFER_SIZE, buffer) != 0)
	{
		index += add_to_stash(stash, buffer, BUFFER_SIZE, index);
		if (is_there_a_new_line(buffer, BUFFER_SIZE) == 1)
		{
			line = divide_the_stash(line, stash);
			break ;
		}
	}
	return (line);
}
