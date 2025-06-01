/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:26:02 by tgeler            #+#    #+#             */
/*   Updated: 2025/05/29 02:26:02 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ndl_len;

	if (*ndl == '\0')
		return ((char *)haystack);
	ndl_len = ft_strlen(ndl);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (j < ndl_len && i + j < len && haystack[i + j] == needle[j])
				j++;
			if (j == ndl_len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
