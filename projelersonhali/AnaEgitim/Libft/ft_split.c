/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:43:45 by tgeler            #+#    #+#             */
/*   Updated: 2025/06/03 19:43:45 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	calculate_words_amount(char const *s, char c)
{
	size_t	i;
	size_t	number_of_words;

	number_of_words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i - 1] != c))
			number_of_words += 1;
		i++;
	}
	if ((s[i - 1] != c) && (i != 0))
		return (number_of_words + 1);
	return (number_of_words);
}

void	fill_it(char **array, size_t j, const char *s, size_t index)
{
	size_t	i;

	k = 0;
	while (array[j][k] != '\0')
	{
		array[j][k] = s[i];
		index++;
		k++;
	}
	return ;
}

void	malloc_for_words(const char *s, char c,char **array)
{
	size_t	i;
	size_t	end;
	size_t	start;
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	i = 0;
	start = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i - 1;
		array[j] = malloc(sizeof(char) * (end - start + 1));
		array[j][end - start] = '\0';
		index = i;
		while ()
		{
			array[j][k] = s[index];
			index++;
			k++;
		}
		i++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	word_amount;
	size_t	i;
	char	**array;

	word_amount = calculate_words_amount(s, c);
	array = malloc(sizeof(char *) * (word_amount + 1));
	array[word_amount] = NULL;
	i = 0;
	if (!array)
		return (NULL);
	malloc_for_words(s, c, array);
}
#include <stdio.h>
int main ()
{
	char const *s = "tugra,geler";
	char c = ',';
	printf("%ld",calculate_words_amount(s,c));
}