/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:01:06 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/06 21:01:06 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "run_map.h"

int	move_player(t_list *map, cordinat_map_infos *player, int x, int y)
{
	textures	images;
	cordinat_map_infos exit;

	images = fill_map_with_images(player);
	if (check_is_wall_collectible(player, '1') == 0)
	{
		if (player->collectibles_amount != 0 && player->collectibles_amount != -42 && check_is_wall_collectible(player, 'C') == 1)
			player->collectibles_amount--;
		mlx_put_image_to_window(player->minilibx , player->window, images->floor, (map->x) * TILE_SIZE, (map->y) * TILE_SIZE);
		mlx_put_image_to_window(player->minilibx , player->window, images->player[0], ((map->x) + x) * TILE_SIZE, ((map->y) + y) * TILE_SIZE);
		(map->x) += x;
		(map->y) += y;
	}
	if (player->collectibles_amount == 0)
	{
		exit.x = find_exits_cordinates(player, 'x');
		exit.y = find_exits_cordinates(player, 'y');
		mlx_put_image_to_window(player->minilibx , player->window, images->exit[0], (exit.x) * TILE_SIZE, (exit.y) * TILE_SIZE);
		player->collectibles_amount = -42;
	}
	return (1);
}
