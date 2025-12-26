/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:26:27 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:26:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_functions.h"

void	print_error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	print_error_int(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (0);
}
