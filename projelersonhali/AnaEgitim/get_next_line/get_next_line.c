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

void	fill_new_stash(char *new_stash, char *src, int start, int length)
{
	int	i;

	i = 0;
	if (!new_stash)
		return ;
	while (i < length)
	{
		new_stash[i] = src[start + i];
		i++;
	}
	return ;
}
char *build_new_malloc_for_stash(char **stash, char *buffer, int bytes_read)
{
	int		total_length;
	char	*new_stash;
	int		old_length;

	old_length = ft_strlen(*stash);
	total_length = old_length + bytes_read;
	new_stash = malloc(total_length + 1);
	if (!new_stash)
		return (NULL);
	fill_it(new_stash, *stash, 0, 0);
	fill_it(new_stash, buffer, old_length, -2);
	new_stash[total_length] = '\0';
	free (*stash);
	return (new_stash);
}

char	*add_to_stash(char **stash, char *buffer, int bytes_read)
{
	if (!*stash)
	{
		*stash = malloc(bytes_read + 1);
		if (!*stash)
			return (NULL);
		(*stash)[bytes_read] = '\0';
		fill_it(*stash, buffer, 0, 0);
		return (*stash);
	}
	else
		*stash = build_new_malloc_for_stash(stash, buffer, bytes_read);
	return (*stash);
}

int	fill_buffer(char **stash, char **line, int fd)
{
	int			bytes_read;
	char		*buffer;
/* 	static	int		i = 1;
	static int 		j = 1; */
/* 	if (i == 1)
	{
		printf("%s",*stash);
	} */
	while (is_there_a_new_line(*stash, ft_strlen(*stash), 0, '1') == 0)
	{
	/* 	if (i == 3)
		{
			printf("%s","DONGU_CALISTI");
		} */
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			buffer[bytes_read] = '\0';
		if (bytes_read <= 0)
		{
			free (buffer);
			return (bytes_read);
		}
		/* if (i == 3)
		{
			printf("%s",buffer);
		} */
		*stash = add_to_stash(stash, buffer, bytes_read);
		free (buffer);
	}
	/*   if (i == 2)
   {
	   printf("%s","STAS_ONCEKI_DURUM:");
	   printf("%s",*stash);
	   printf("%s","UZUNLUK_STASH:");
	   printf("%d",ft_strlen(*stash));
   } */
	if (is_there_a_new_line(*stash, ft_strlen(*stash), 0, '1') != 0)
		*line = divide_the_stash(line, stash);
 	/* if (i == 2)
   {
		printf("%s","STAS_SONRAKI_DURUM:");
	   printf("%s",*stash);
	   printf("%s","UZUNLUK_STASH:");
	   printf("%d",ft_strlen(*stash));
   } */
	//i++;
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;
	//static int		i = 1;
	line = NULL;
	if (fd < 0)
		return (line);
	/* if (i == 2)
	 {
		printf("%s","BUSTASHTIR");
		 printf("%s",stash);
	 } */
	fill_buffer(&stash, &line,fd);
	// i++;
	return (line);

}





			/* printf("%s",*stash);
			printf("%s","UZUNLUK_STASH:");
			printf("%d",ft_strlen(*stash));
			printf("%s","DIGERSTASH:"); */