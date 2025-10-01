/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initilaze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:30:22 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/01 23:18:59 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_map.h"

t_list *save_map_in_linked_list(t_list *map, int fd)
{
	char	*line;
	int		i;
	char	*previous_line;
	
	i = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (i != 0)
			line = get_next_line(fd);
		ft_lstadd_back(&map, ft_lstnew(line));
		free(line);
		i++;
	}
	return (map);
}

window management window_initilaze(t_list *map)
{
	window_management	win;
	
	win.width = TILE_SIZE * calculate_width_or_height(map, 'w');
	win.length = TILE_SIZE * calculate_width_or_height(map, 'l');
	win.minilibx = mlx_init();
	if (!(win.minilibx))
		return (-2);
	win.window = mlx_new_window(win.minilibx, win.width, win.length , "so_long");
	if (!(win.window))
		return (-3);
	return (win);
}
