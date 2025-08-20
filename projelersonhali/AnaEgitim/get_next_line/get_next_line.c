/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:04:26 by tgeler            #+#    #+#             */
/*   Updated: 2025/07/30 00:04:26 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill_it(char *stash, char *line, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		line[i] = stash[i];
		i++;
	}
	return ;
}
char	*control_statements(char *stash, char *line, int length)
{
	int	j;

	j = 0;
	if (ft_strchr(stash, '\n') == NULL)
	{
		fill_it(stash, line, length);
		return (line);
	}
	while (stash[j] != '\n')
	{
		line[j] = stash[j];
		j++;
	}
	stash = ft_strchr(stash, '\n');
	return (line);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;
	char		buffer[BUFFER_SIZE];
	char		*new_str;
	size_t		i;

	line = NULL;
	i = 0;
	buffer[0] = 't';
	while (buffer[i] != '\n')
	{
		read (fd, buffer, BUFFER_SIZE);
		new_str = ft_strjoin(stash, buffer);
		ft_strlcpy(stash, new_str, ft_strlen(new_str));
		free(new_str);
	}
	return(control_statements(stash, line, ft_strlen(stash)));
}
