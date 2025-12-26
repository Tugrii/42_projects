/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_over_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

static int	check_is_over_limit_utils(int last_index, char *str, int sign)
{
	long long	result;
	long long	calc;
	int			len;

	len = ft_strlen(str);
	result = 0;
	result += str[last_index] - '0';
	calc = 10;
	last_index--;
	if ((str[0] == '-' || str[0] == '+') && len > 11)
		return (1);
	else if (len > 10 && !(str[0] == '-' || str[0] == '+'))
		return (1);
	while (last_index != -1
		&& !(str[last_index] == '-' || str[last_index] == '+'))
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

int	check_is_over_limit(char **argv)
{
	int			i;
	int			sign;
	int			last_index;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			last_index = ft_strlen(argv[i]) - 1;
			sign = 1;
			if (argv[i][0] == '-' || argv[i][0] == '+')
			{
				if (argv[i][0] == '-')
					sign = -1;
			}
			if (check_is_over_limit_utils(last_index, argv[i], sign))
				return (1);
			i++;
		}
	}
	return (0);
}
