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

#include "ft_printf.h"

int	process3(const char *sub_type, va_list *argument)
{
	unsigned int	unsigned_integer;

	if (*sub_type == 'x' || *sub_type == 'X')
	{
		unsigned_integer = va_arg(*argument, unsigned int);
		if (*sub_type == 'x')
			return (ft_puthex(unsigned_integer, 0, 0));
		else
			return (ft_puthex(unsigned_integer, 1, 0));
	}
	if (*sub_type == 'u')
	{
		unsigned_integer = va_arg(*argument, unsigned int);
		return (put_un_int(unsigned_integer, 0));
	}
	return (0);
}

int	process2(const char *sub_type, va_list *argument)
{
	void			*ptr;

	if (*sub_type == '%')
		return (write(1, "%", sizeof(char)));
	if (*sub_type == 'p')
	{
		if (*sub_type == 'p')
		{
			ptr = va_arg(*argument, void *);
			if (ptr == 0)
				return (write (1, "(nil)", 5));
			write (1, "0x", 2);
			return (2 + ft_puthex((unsigned long)ptr, 0, 0));
		}
	}
	return (process3(sub_type, argument));
}

int	process1(const char *sub_type, va_list *argument)
{
	int		integer;
	char	*string;

	if (*sub_type == 'd' || *sub_type == 'i' || *sub_type == 'c')
	{
		integer = va_arg(*argument, int);
		if (*sub_type != 'c')
			ft_putnbr_fd(integer, 1);
		else
			return (write(1, &integer, 1));
		return (count_size_of_int(integer, integer));
	}
	if (*sub_type == 's')
	{
		string = va_arg(*argument, char *);
		if (string == NULL)
			return (write(1, "(null)", 6));
		ft_putstr_fd(string, 1);
		return (ft_strlen(string));
	}
	return (process2(sub_type, argument));
}

int	ft_printf(const char *type, ...)
{
	va_list		argument;
	const char	*type_list;
	int			return_value;

	return_value = 0;
	type_list = "cspdiuxX%";
	va_start(argument, type);
	while (*type != '\0')
	{
		while (!(*type == '%' && ft_strchr(type_list, *(type + 1)))
			&& *type != '\0')
		{
			write (1, type, sizeof(char));
			return_value += 1;
			type++;
		}
		if (*type == '%' && ft_strchr(type_list, *(type + 1)))
		{
			return_value += process1(type + 1, &argument);
			type += 2;
		}
	}
	va_end(argument);
	return (return_value);
}
