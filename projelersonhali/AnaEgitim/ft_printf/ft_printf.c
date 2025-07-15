/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:08:13 by tgeler            #+#    #+#             */
/*   Updated: 2025/07/13 20:08:13 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
int	count_size_of_int(int value)
{
	int	i;
	if (value >= 0)
		i = 1;
	if (value < 0)
	{
		value *= -1;
		i = 2;
	}
	while (value / 10)
	{
		value /= 10;
		i++;
	}
	return (i);
}
int	process2(const char *sub_type, va_list *argument, const char *type_list)
{

}

int	process1(const char *sub_type, va_list *argument, const char *type_list)
{
	int		integer;
	char	*string;

	if (*sub_type == 'd' || *sub_type == 'i' || *sub_type == 'c')
	{
		integer = va_arg(*argument, int);
		if (*sub_type != 'c')
			ft_putnbr_fd(integer, 1);
		else
		{
			ft_putchar_fd(integer, 1);
			return (1);
		}
		return (count_size_of_int(integer));
	}
	if (*sub_type == 's')
	{
		string = va_arg(*argument, char *);
		if (string == NULL)
			return (write(1, "(null)", 6));
		ft_putstr_fd(string, 1);
		return(ft_strlen(string));
	}
	return (process2(sub_type, argument, type_list));
}
int	ft_printf(const char *type, ...)
{
	va_list		argument;
	const char *type_list;
	int			return_value;

	return_value = 0;
	type_list = "cspdiuxX%";
	va_start(argument, type);
	while (*type != '\0')
	{
		while (!(*type == '%' && ft_strchr(type_list, *(type + 1))) && *type != '\0')
		{
			write (1, type, sizeof(char));
			return_value += 1;
			type++;
		}
		if (*type == '%' && ft_strchr(type_list, *(type + 1)))
		{
			return_value += process1(type + 1, &argument, type_list);
			type += 2;
		}
	}
	return (return_value);
}
int main ()
{
	printf("%d",ft_printf("%s",NULL));
}