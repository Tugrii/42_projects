/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_one_exit_and_start_utils.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:34:53 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 17:32:07 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/Libft/libft.h"

int	exit_start_counter(t_list *traversal, char mode)
{
	char	*line;
	int		length_line;
	int		i;
	int		number_of_e_or_p;

	number_of_e_or_p = 0;
	i = 0;
	line = traversal->content;
	length_line = ft_strlen(line);
	while (i < (length_line - 1))
	{
		if (line[i] == mode)
			number_of_e_or_p++;
		i++;
	}
	return(number_of_e_or_o);
}
