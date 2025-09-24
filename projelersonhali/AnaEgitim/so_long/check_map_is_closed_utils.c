/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:39:05 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/24 19:09:58 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/Libft/libft.h"

int check_interval_line(t_list *traversal)
{
	int		line_length;
	char	*line;

	line = (traversal->content);
	line_length = ft_strlen(line);
	if (line[0] != '1' || line[line_length - 1] != '1')
		return (0);
	return (1);
}
