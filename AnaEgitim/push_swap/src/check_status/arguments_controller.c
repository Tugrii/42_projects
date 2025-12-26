/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:26:27 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:26:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../error_functions/error_functions.h"

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
