/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:39:05 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 17:31:56 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/Libft/libft.h"

int	check_last_and_initial(t_list	*traversal, int length_line)
{
	char	*line;
	int		i;
	
	line = traversal->content;
	i = 0;
	while (i < (length_line - 1))
	{
		if (line[i] != '1')
			return (0);
		i++;
	}	
}
int check_interval_line(t_list	*traversal, int line_length)
{
	char	*line;

	line = (traversal->content);
	if (line[0] != '1' || line[line_length - 2] != '1')
		return (0);
	return (1);
}
