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

int	move_player(cordinat_map_infos *player, int x, int y)
{
	textures	images;
	cordinat_map_infos exit;
	window_management	temp;
	
	temp = take_the_struct(player);
	images = fill_map_with_images(&temp);
	if (check_is_wall_collectible(player, x, y) != 1)
	{
		if ((player->collectibles_amount) != -1)
			check_is_wall_collectible(player, x, y);
		mlx_put_image_to_window(player->minilibx , player->window, images.floor, (player->x) * TILE_SIZE, (player->y) * TILE_SIZE);
		mlx_put_image_to_window(player->minilibx , player->window, images.player[0], ((player->x) + x) * TILE_SIZE, ((player->y) + y) * TILE_SIZE);
		(player->x) += x;
		(player->y) += y;
		(player->movements_amount)++;
		ft_printf("Move Number : %d\n", player->movements_amount);
	}
	if (player->collectibles_amount == 0)
	{
		exit.x = find_exits_cordinates(player, 'x');
		exit.y = find_exits_cordinates(player, 'y');
		mlx_put_image_to_window(player->minilibx , player->window, images.exit[0], (exit.x) * TILE_SIZE, (exit.y) * TILE_SIZE);
		player->collectibles_amount = -1;
	}
	return (1);
}
