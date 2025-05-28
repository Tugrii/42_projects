/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:17:40 by tgeler            #+#    #+#             */
/*   Updated: 2025/02/28 10:06:26 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
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
	while (src[i] != '\0' && i < nb)
	{
		dest[presizeofdest + i] = src[i];
		i++;
	}
	dest[presizeofdest + i] = '\0';
	return (dest);
}
