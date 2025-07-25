/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_f1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:08:07 by tgeler            #+#    #+#             */
/*   Updated: 2025/07/17 19:08:07 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_un_int_fd(unsigned int value, int fd, int counter)
{
	char	digit;

	if (value >= 10)
		counter = put_un_int_fd(value / 10, fd, counter);
	digit = (value % 10) + '0';
	write(fd, &digit, 1);
	return (counter + 1);
}

int	ft_puthex_fd(unsigned long value, int fd, int is_upper, int counter)
{
	char	*base;

	if (is_upper == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (value >= 16)
		counter = ft_puthex_fd(value / 16, fd, is_upper, counter);
	write(fd, &base[value % 16], 1);
	return (counter + 1);
}

int	count_size_of_int(int value, int previous_value)
{
	size_t	i;

	i = 1;
	while (value / 10)
	{
		value /= 10;
		i++;
	}
	if (previous_value >= 0)
		return (i);
	else
		return (i + 1);
}
