/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_are_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

int	check_all_are_number(char **argv)
{
	int	i;
	int	length;
	int	j;

	i = 1;
	if (argv)
	{
		while (argv[i])
		{
			j = 0;
			length = ft_strlen(argv[i]);
			if (length > 1 && (argv[i][0] == '-' || argv[i][0] == '+'))
				j = 1;
			while (j < length)
			{
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}
