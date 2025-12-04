/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:26:27 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 14:54:03 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_functions.h"

int	print_error_int(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (0);
}
char *print_error_char(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (NULL);
}
