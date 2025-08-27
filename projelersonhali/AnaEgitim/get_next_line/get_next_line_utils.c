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

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
char	*last_stash_controls(char **stash, char **line)
{
	int	length;

	if (!*stash)
		return (*line);
	length = ft_strlen(*stash);
	*line = malloc(length + 1);
	if (!*line)
		return(NULL);
	(*line)[length] = '\0';
	fill_it(*line, *stash, length, 0);
	free(*stash);
	*stash = NULL;
	return (*line);
}

char	*divide_the_stash(char *line, char **stash)
{
	int		length_line;
	char	*new_stash;
	int		length_new_stash;

	//printf("%s","girdim");
	length_line = is_there_a_new_line(*stash, ft_strlen(*stash), 0);
	//printf("%d",length_line);
	line = malloc(length_line + 1);
	if (!line)
		return (NULL);
	line[length_line] = '\0';
	length_new_stash = ft_strlen(*stash) - length_line;
	fill_it(line, *stash, length_line, 0);
	if (length_new_stash == 0)
	{
		//printf("%s","FERRO");
		free (*stash);
		*stash = NULL;
	}  
	else
	{
		//printf("%s","TRİGONOMETRİ");
		new_stash = malloc(length_new_stash + 1);
		if (!new_stash)
			return (NULL);
		new_stash[length_new_stash] = '\0';
		fill_it(new_stash, *stash, length_new_stash, length_line);
		//printf("%s",*stash);
		//printf("%s",new_stash);
		free (*stash);
		*stash = new_stash;
	}
	return (line);
}

int	is_there_a_new_line(char *stash, int bytes_read, int i)
{
	while (i < bytes_read)
	{
		if (stash[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
