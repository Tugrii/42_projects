/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_with_clean_way.h"

int	exit_wit_clean_way1(char **str1, char **str2, int fd)
{
	int	i;

	i = 0;
	if (str1)
	{
		while (str1[i])
		{
			free (str1[i]);
			i++;
		}
		free (str1);
	}
	i = 0;
	if (str2)
	{
		while (str2[i])
		{
			free (str2[i]);
			i++;
		}
		free (str2);
	}
	if (fd == 2)
		return (print_error_int("Error! Malloc failed!!!\n"));
	return (1);
}
int	exit_wit_clean_way2(char	**str1, char *str2, char *str3, int fd)
{
	int	i;

	i = 0;
	if (str1)
	{
		while (str1[i])
		{
			free (str1[i]);
			i++;
		}
		free (str1);
	}
	if (str2)
		free (str2);
	if (str3)
		free (str3);
	if (fd == 2)
		return (print_error_int("Error! Malloc failed!!!\n"));
	return (1);
}
