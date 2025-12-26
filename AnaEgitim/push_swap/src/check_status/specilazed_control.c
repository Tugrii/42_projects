/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specilazed_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	specilazed_control(char *str)
{
	size_t	index1;
	size_t	index2;
	size_t	number_of_white_spaces;
	char	*white_spaces;

	if (!str)
		return (0);
	white_spaces = " \t\n\v\f\r";
	index1 = 0;
	number_of_white_spaces = 0;
	while (str[index1] != '\0')
	{
		index2 = 0;
		while (index2 < 6)
		{
			if (str[index1] == white_spaces[index2])
				number_of_white_spaces++;
			index2++;
		}
		index1++;
	}
	if (number_of_white_spaces == index1)
		return (0);
	return (index1);
}
