/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:14:27 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/01 16:14:27 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_;
	const char	*src_;
	size_t		i;

	i = 0;
	dest_ = (char *)dest;
	src_ = (const char *)src;
	while (i < n)
	{
		dest_[i] = src_[i];
		i++;
	}
	return (dest);
}
