/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:45:03 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:45:03 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libf.h"

char	f(unsigned int i, char c)
{
	void(i);
	return (ft_tolower(c));
}
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	i;
	size_t	size;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	array = malloc(sizeof(char) * (size + 1));
	if (!array)
		return (NULL);
	array[size] = '\0';
	while (i < size)
	{
		array[i] = f(i, s[i]);
		i++;
	}
	return (array);
}
#include <stdio.h>

int main ()
{
	char	*s = "tugrageleradamdir";
	printf("%s",ft_strmapi(s, f));
}