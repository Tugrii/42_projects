/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_over_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:03:03 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/29 01:03:03 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

static int	check_is_over_limit_utils(int last_index, char *str, int sign)
{
	long long	result;
	int			calc;

	result = 0;
	result += str[last_index] - '0';
	calc = 10;
	last_index--;
	while (last_index != -1 && !(str[last_index] == '-' || str[last_index] == '+'))
	{
		result += calc * (str[last_index] - '0');
		calc *= 10;
		last_index--;
	}
	result *= sign;
	if ((result >= -2147483648 && result <= 2147483647))
		return (0);
	return (1);
}

int check_is_over_limit(int argc, char **argv)
{
	int			i;
	int			sign;
	int			last_index;

	i = 1;
	while (i < argc)
	{
		last_index = ft_strlen(argv[i]) - 1;
		sign = 1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			if (argv[i][0] == '-')
				sign = -1;
		}
		if (check_is_over_limit_utils(last_index, argv[i], sign) == 1)
			return (1);
		i++;
	}
	return (0);
}
