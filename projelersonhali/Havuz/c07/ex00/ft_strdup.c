/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:41:30 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/12 18:29:10 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*area;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	area = (char *)malloc(len + 1);
	if (area == NULL)
		return (NULL);
	while (i < len)
	{
		area[i] = src[i];
		i++;
	}
	area[i] = '\0';
	return (area);
}
