/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:07:03 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/04 11:11:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	to_find_size(char *to_find)
{
	int	a;

	a = 0;
	while (to_find[a] != '\0')
	{
		a++;
	}
	return (a);
}

int	comp_subs(int b, int c, char *str_comp, char *to_find_comp)
{
	int	i;

	i = 0;
	while (i < c && str_comp[b + i] == to_find_comp[i])
	{
		i++;
	}
	return (i == c);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	size_find;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	size_find = to_find_size(to_find);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0] && comp_subs(i, size_find, str, to_find))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
