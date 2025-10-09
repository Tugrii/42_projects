/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_has_valid_name.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:32:09 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 18:32:09 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/Libft/libft.h"

int	check_file_has_valid_name(char	*file_name)
{
	int		length;

	length = ft_strlen(file_name);
	if (length > 4)
	{
		if (file_name[length - 1] == 'r'
			&& file_name[length - 2] == 'e'
			&& file_name[length - 3] == 'b'
			&& file_name[length - 4] == '.'
			&& file_name[length - 5] != '/')
				return (1);
		else
			return (0);
	}
	return (0);
}
