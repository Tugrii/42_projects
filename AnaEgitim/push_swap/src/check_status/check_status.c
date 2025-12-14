/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:46:01 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/28 21:46:01 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

int	check_status(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (check_all_are_number(argc, argv) == 1)
	{
		if (check_is_over_limit(argc, argv) == 1)
			return (error_messages(1));
		if (argc == 2)
			return (0);
		if (check_is_there_duplicate(argc, argv) == 1)
			return (error_messages(1));
	}
	else
		return (0);
	return (1);
}
