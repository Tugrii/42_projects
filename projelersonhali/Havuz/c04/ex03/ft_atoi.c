/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:07 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/13 20:05:46 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
int	is_whitespace(char *ptr)
{
	int		i1;
	int		i2;
	int		i3;
	char	c_ptr[6];

	i1 = 0;
	i3 = 0;
	c_ptr[0] = ' ';
	c_ptr[1] = '\t';
	c_ptr[2] = '\n';
	c_ptr[3] = '\v';
	c_ptr[4] = '\f';
	c_ptr[5] = '\r';
	while (ptr[i1] != '\0')
	{
		i2 = 0;
		while (i2 < 6)
		{
			if (ptr[i1] == c_ptr[i2])
				i3++;
			i2++;
		}
		i1++;
	}
	return (i3);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = is_whitespace(str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
int main()
{
	char arr1[]="       \n \t     -+-+-3478974";
	printf("%d",ft_atoi(arr1));
}