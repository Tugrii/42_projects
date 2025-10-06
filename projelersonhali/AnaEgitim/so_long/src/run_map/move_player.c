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
	int	pre_x;
	int	pre_y;
	textures	images;

	pre_x = player->x;
	pre_y = player->y;
	if (check_is_wall_collectible(player, '1') == 0)
	{
		if (player->collectible_amount != 0 && check_is_wall_collectible(player, 'C') == 1)
			player->collectible_amount--;
		images = fill_map_with_images(player);
		mlx_put_image_to_window(player->minilibx , player->window, images->floor, (map->x) * TILE_SIZE, (map->y) * TILE_SIZE);
		mlx_put_image_to_window(player->minilibx , player->window, images->player[0], ((map->x) + x) * TILE_SIZE, ((map->y) + y) * TILE_SIZE);
	}

}
