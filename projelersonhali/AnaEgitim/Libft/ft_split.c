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
#include <stdio.h>

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
		if ((i > 0) && (s[i] == c) && (s[i - 1] != c))
			number_of_words += 1;
		i++;
	}
	if ((s[i - 1] != c) && (i != 0))
		return (number_of_words + 1);
	return (number_of_words);
}

void	fill_it(const char *s, char **array, size_t start, size_t end)
{
	static size_t	i = 0;
	size_t			j;
	static size_t	word_amount;

	if (i == 0)
		word_amount = calculate_words_amount(s, s[end]);
	j = 0;
	while (start < end)
	{
		array[i][j] = s[start];
		start++;
		j++;
	}
	array[i][j] = '\0';
	i++;
	if (word_amount == i)
		i = 0;
	return ;
}

int	if_null(char **array, size_t j)
{
	size_t	i;

	if (!array[j])
	{
		i = 0;
		while (i < j)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (0);
	}
	return (1);
}

int	malloc_for_words(const char *s, char c, char **array, size_t j)
{
	static size_t	i = 0;
	size_t			end;
	size_t			start;

	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i;
		array[j] = malloc(sizeof(char) * (end - start + 1));
		if (if_null(array, j) == 0)
		{
			i = 0;
			return (0);
		}
		fill_it(s, array, start, end);
		j++;
		i++;
	}
	i = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_amount;
	char	**array;
	int		is_worked;

	if (!s)
		return (NULL);
	word_amount = calculate_words_amount(s, c);
	array = malloc(sizeof(char *) * (word_amount + 1));
	if (!array)
		return (NULL);
	array[word_amount] = NULL;
	is_worked = malloc_for_words(s, c, array, 0);
	if (is_worked == 0)
		return (NULL);
	return (array);
}
