/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_clean_way.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_with_clean_way.h"

static int	exit_with_clean_way1(char **str1, t_list **list)
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
	if (list)
	{
		while (*list)
		{
			free (*list);
			*list = *(list->next);
		}
		free (list);
	}
	return (1);
}

static int	exit_with_clean_way2(char **str1, char *str2, char *str3)
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
	return (1);
}

int	clean_and_exit(t_push_swap *push_swap, int exit_type, char *msg)
{
	exit_with_clean_way1(push_swap->splitted_arguments, &(push_swap->list));
	exit_with_clean_way2(NULL, NULL, NULL);
	if (msg)
		print_error_exit(msg, exit_type);
	exit(exit_type);
}
