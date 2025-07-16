/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:28:12 by tgeler            #+#    #+#             */
/*   Updated: 2025/07/06 10:28:12 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
<<<<<<< HEAD
	size_t	count = 0;
	int		in_word = 0;

	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
=======
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
>>>>>>> 5c9a5e10c143154e30ceb8e313541c8ba8d316b7
	}
	return (count);
}

<<<<<<< HEAD
static size_t	word_len(const char *s, char c)
{
	size_t	len = 0;

	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_all(char **arr, size_t i)
=======
static char	**free_all(char **arr, size_t i)
>>>>>>> 5c9a5e10c143154e30ceb8e313541c8ba8d316b7
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
<<<<<<< HEAD
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	words;
	size_t	i = 0;
	size_t	len;
=======
	return (NULL);
}

static char	**fill_words(const char *s, char c, size_t words)
{
	char		**result;
	size_t		i;
	size_t		len;

	i = 0;
	result = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		result[i] = ft_substr(s, 0, len);
		if (!result[i])
			return (free_all(result, i));
		s += len;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;
>>>>>>> 5c9a5e10c143154e30ceb8e313541c8ba8d316b7

	if (!s)
		return (NULL);
	words = count_words(s, c);
<<<<<<< HEAD
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		result[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[i])
		{
			free_all(result, i);
			return (NULL);
		}
		for (size_t j = 0; j < len; j++)
			result[i][j] = s[j];
		result[i][len] = '\0';
		s += len;
		i++;
	}
	result[i] = NULL;
=======
	result = fill_words(s, c, words);
>>>>>>> 5c9a5e10c143154e30ceb8e313541c8ba8d316b7
	return (result);
}

