/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:41:34 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/12 18:24:14 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*area;
	int	i;
	int	len;

	i = 0;
	if (min == max || min > max)
		return (NULL);
	else
		len = max - min;
	area = (int *)malloc((len + 1) * 4);
	if (area == NULL)
		return (NULL);
	while (i < len)
	{
		area[i] = i + min;
		i++;
	}
	area[i] = '\0';
	return (area);
}
