/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initilaze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:30:22 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/07 00:08:46 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_map.h"

t_list *save_map_in_linked_list(t_list *map, int fd)
{
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (map);
}

void window_initilaze(t_list *map, window_management	*win)
{	
	win->width = TILE_SIZE * calculate_width_or_height(map, 'w');
	win->length = TILE_SIZE * calculate_width_or_height(map, 'l');
	win->minilibx = mlx_init();
	if (!(win->minilibx))
		return ;
	win->window = mlx_new_window(win->minilibx, win->length, win->width , "so_long");
	if (!(win->window))
		return ;
	return ;
}
