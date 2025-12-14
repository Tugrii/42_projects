/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_are_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:01:19 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/29 01:01:19 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

int	check_all_are_number(int argc, char **argv)
{
	int	i;
	int	length;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		length = ft_strlen(argv[i]);
		if (length > 1 && (argv[i][0] == '-' || argv[i][0] == '+'))
			j = 1;
		while (j < length)
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (error_messages(1));
			j++;
		}
		i++;
	}
	return (1);
}