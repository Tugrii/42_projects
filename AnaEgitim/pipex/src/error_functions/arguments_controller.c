/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:26:27 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_functions.h"

void	arguments_controller(int argc, int argument_limit)
{
	char	*temp;

	if (argc != argument_limit + 1)
	{
		temp = ft_itoa(argument_limit);
		print_error_int("Argument count is not : ");
		print_error_int(temp);
		free (temp);
		print_error_int("!\n");
		exit(1);
	}
	return ;
}
