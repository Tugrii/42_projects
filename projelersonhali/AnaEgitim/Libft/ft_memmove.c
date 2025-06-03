/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:30:42 by marvin            #+#    #+#             */
/*   Updated: 2025/06/02 22:30:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*start_from_back(char *dest, const char *src, size_t n)
{
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	*start_from_beginning(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_;
	const char	*src_;

	dest_ = (char *)dest;
	src_ = (const char *)src;
	if ((dest_ == src_) || (n == 0))
		return (dest);
	else if (dest_ < src_)
		return ((void *)start_from_beginning(dest_, src_, n));
	else
		return ((void *)start_from_back(dest_, src_, n));
}
