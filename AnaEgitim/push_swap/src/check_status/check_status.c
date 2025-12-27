/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

static int	check_status_utils2(char **argv)
{
	if (check_all_are_number(argv))
	{
		if (!check_is_over_limit(argv))
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	check_status_utils1(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		if (specilazed_control(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_status(int argc, char **argv, char step)
{
	if (step == '1')
		return (check_status_utils1(argc, argv));
	if (step == '2')
		return (check_status_utils2(argv));
	return (1);
}
