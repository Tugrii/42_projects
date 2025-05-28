/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:28:38 by tgeler            #+#    #+#             */
/*   Updated: 2025/02/26 14:30:07 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	presizeofdest;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	presizeofdest = i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[presizeofdest + i] = src[i];
		i++;
	}
	dest[presizeofdest + i] = '\0';
	return (dest);
}
