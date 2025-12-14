/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_initial_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:40:40 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/06 21:40:40 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_map.h"

void	find_initial_position(t_cordinat_map_infos *player)
{
	t_list	*traversal;
	char	*line;

	traversal = player->map_content;
	player->map_length = ft_strlen(traversal->content) - 1;
	player->y = 0;
	while (traversal)
	{
		line = traversal->content;
		player->x = 0;
		while (player->x < player->map_length)
		{
			if (line[player->x] == 'P')
				return ;
			player->x++;
		}
		player->y++;
		traversal = traversal->next;
	}
	return ;
}
