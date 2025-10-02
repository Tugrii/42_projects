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
	char	*matched;

	length = ft_strlen(file_name);
	matched = ft_strnstr(file_name, ".ber", length);
	if (matched)
	{
		if (matched[4] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}