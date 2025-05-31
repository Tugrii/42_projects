/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:26:02 by tgeler            #+#    #+#             */
/*   Updated: 2025/05/29 02:26:02 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_calculate_strnstr(const char *haystack, const char *needle, size_t len,size_t len_sub)
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;
	const char	*ptr;
	size_t	len_sub;
	size_t	matched;

	matched = 0;
	len_sub = ft_strlen(needle);
	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			ptr = &haystack[i];
			j = 0;
			a = i;
			while (j < len_sub)
			{
				if ((haystack[a] == needle[j])&&
					(haystack[a] != '\0'))
					matched++;
				else
				{
					matched = 0;
					break ;
				}
				a++;
				j++;
			}
			if (matched == len_sub)
				return ((char*)ptr);
			i = a;
		}
		i++;
	}
	return (NULL);
}
int main ()
{
char *haystack = "example";
char *needle = "";
size_t len = 7;
printf("%s",ft_strnstr(haystack,needle,len));

}