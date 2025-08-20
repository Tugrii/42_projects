/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:37:40 by tgeler            #+#    #+#             */
/*   Updated: 2025/07/30 00:37:40 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while ((i < dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)(c))
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	prefix_length;
	size_t	j;

	j = 0;
	prefix_length = ft_strlen(s1);
	i = 0;
	new_str = (char *)malloc(ft_strlen(s2) + prefix_length + 1);
	if (!new_str)
		return (NULL);
	while (i < prefix_length)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s2) + prefix_length))
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
