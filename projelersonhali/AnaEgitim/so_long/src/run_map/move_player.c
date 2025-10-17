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
	if (check_is_wall_collectible(player, x, y) != 1)
	{
		if (check_is_door(player, x , y) == 1)
		{
			mlx_put_image_to_window(player->minilibx , player->window, player->images->exit[2], (player->exit_x) * TILE_SIZE, (player->exit_y) * TILE_SIZE);
			mlx_put_image_to_window(player->minilibx , player->window, player->images->floor, (player->x) * TILE_SIZE, (player->y) * TILE_SIZE);
		}
		if (check_is_door(player, x , y) == 2)
			mlx_put_image_to_window(player->minilibx , player->window, player->images->exit[1], (player->exit_x) * TILE_SIZE, (player->exit_y) * TILE_SIZE);
		if (check_is_door(player, x ,y) != 1)
		{
			if (check_is_door(player, x, y) != 2)
				mlx_put_image_to_window(player->minilibx , player->window, player->images->floor, (player->x) * TILE_SIZE, (player->y) * TILE_SIZE);
			mlx_put_image_to_window(player->minilibx , player->window, player->images->player[0], ((player->x) + x) * TILE_SIZE, ((player->y) + y) * TILE_SIZE);
		}
		if ((player->collectibles_amount) != -1)
			check_is_wall_collectible(player, x, y);
		(player->x) += x;
		(player->y) += y;
		(player->movements_amount)++;
		ft_printf("Move Number : %d\n", player->movements_amount);
	}
	if (player->collectibles_amount == -1)
		mlx_put_image_to_window(player->minilibx , player->window, player->images->exit[0], (player->exit_x) * TILE_SIZE, (player->exit_y) * TILE_SIZE);
	return (1);
}
