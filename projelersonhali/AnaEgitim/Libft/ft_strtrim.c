/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:45:58 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:45:58 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static size_t	how_many(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	matched_char;

	matched_char = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				matched_char++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (matched_char);
}

static char	*trim_it(char const *s1, char const *set, char *dynamic)
{
	size_t	i;
	size_t	j;
	char	*trimmed_str;
	size_t	a;

	trimmed_str = dynamic;
	a = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
		{
			trimmed_str[a] = s1[i];
			a++;
		}
		i++;
	}
	return (trimmed_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dynamic_memory;

	dynamic_memory = (char *)malloc(ft_strlen(s1) - how_many(s1, set) + 1);
	if (!dynamic_memory)
		return (NULL);
	return (trim_it(s1, set, dynamic_memory));
}
