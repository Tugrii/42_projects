/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:46:00 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:46:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dynamic;
	size_t	total_length;

	if (!s)
		return (NULL);
	total_length = ft_strlen(s);
	if ((start >= total_length) || (len > (total_length - start)))
		return (ft_strdup(""));
	dynamic = malloc(sizeof(char) * (len + 1));
	if (!dynamic)
		return (NULL);
	dynamic[len] = '\0';
	s += start;
	i = 0;
	while (i < len)
	{
		*(dynamic + i) = *(s + i);
		i++;
	}
	return (dynamic);
}
