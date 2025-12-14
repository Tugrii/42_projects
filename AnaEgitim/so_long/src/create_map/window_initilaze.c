/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initilaze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:30:22 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/07 18:31:16 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_map.h"

t_list	*save_map_in_linked_list(t_list *map, int fd)
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

int	window_initilaze(t_list *map, t_window_management	*win)
{
	int	screen_w;
	int	screen_h;

	win->w = TILE_SIZE * calculate_width_or_height(map, 'w');
	win->h = TILE_SIZE * calculate_width_or_height(map, 'h');
	win->minilibx = mlx_init();
	if (!(win->minilibx))
		return (0);
	mlx_get_screen_size(win->minilibx, &screen_w, &screen_h);
	if (win->w > screen_w || win->h > screen_h)
	{
		ft_printf("Error!\nThe map could'nt created. Map size is too much!\n");
		mlx_destroy_display(win->minilibx);
		free(win->minilibx);
		return (0);
	}
	win->window = mlx_new_window(win->minilibx, win->w, win->h, "so_long");
	if (!(win->window))
		return (0);
	return (1);
}
