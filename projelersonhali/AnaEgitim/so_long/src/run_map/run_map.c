/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:17:00 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/06 21:17:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "run_map.h"

int	run_map(t_list *map, window_management *win)
{
	cordinat_map_infos	player;

	player.map_content = map;
	player.minilibx = win->minilibx;
	player.window = win->window;
	player.movements_amount = 0;
	player.map_length = ft_strlen(map->content) - 1;
	find_first_clb_amount(&player);
	find_initial_position(&player);
	mlx_hook(win->window, 17, 0, handle_close, &player);
	mlx_hook(win->window, 2, (1L << 0) , handle_key, &player);
	mlx_loop(win->minilibx);
	return (0);
}
//mlx_put_image_to_window(win->minilibx , win->window, image->wall, (cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
