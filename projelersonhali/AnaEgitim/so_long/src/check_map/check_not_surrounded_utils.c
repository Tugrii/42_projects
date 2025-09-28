/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_not_surrounded_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:48:55 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 16:48:55 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "check_status.h"

char	*find_start(t_list *map, int length_line)
{
	t_list	*traversal;
	char	*line;
	int		i;

	i = 0;
	traversal = map;
	while (traversal)
	{
		line = traversal->content;
		while (i < length_line)
		{
			if(line[i] == 'P')
				return (line + i);
			i++;
		}
		traversal = traversal->next;
	}
	return (NULL);
}
