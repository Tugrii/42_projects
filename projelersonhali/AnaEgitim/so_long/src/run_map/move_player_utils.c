/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:43:33 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/06 22:43:33 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "run_map.h"

int	check_is_wall_collectible(cordinat_map_infos *map, char mode)
{
	char	*line;
	t_list	*traversal;
	int		line_number;

	line_number = 0;
	traversal = map->map_content;
	while (line_number < map->y)
	{
		line_number++;
		traversal = traversal->next;
	}
	line = traversal->content;
	if (line[map->x] == mode)
		return (1);
	return (0);
}
int	find_exits_cordinates(cordinat_map_infos *exit, char mode)
{
	t_list *traversal;
	char	*line;
	int		x;
	int		y;

	traversal = exit->map_content;
	while (traversal)
	{
		line = traversal->content;
		x = 0;
		while (x < exit->map_length)
		{
			if (line[x] == 'E' && mode == 'x')
				return (x);
			if (line[x] == 'E' && mode == 'y')
				return (y);
			x++;
		}
		y++;
		traversal = traversal->next;
	}
	return (0);
}
