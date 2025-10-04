/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initilaze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:30:22 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/04 15:44:24 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_map.h"

t_list *save_map_in_linked_list(t_list *map, int fd)
{
	char	*line;
	t_list	*new_node;
	
	line = get_next_line(fd);
	while (line)
	{
		new_node = ft_lstnew(line);
		ft_lstadd_back(&map, new_node);
		line = get_next_line(fd);
	}
	return (map);
}

window_management window_initilaze(t_list *map)
{
	window_management	win;
	
	win.width = TILE_SIZE * calculate_width_or_height(map, 'w');
	win.length = TILE_SIZE * calculate_width_or_height(map, 'l');
	win.minilibx = mlx_init();
	if (!(win.minilibx))
		return (win);
	win.window = mlx_new_window(win.minilibx, win.width, win.length , "so_long");
	if (!(win.window))
		return (win);
	return (win);
}
