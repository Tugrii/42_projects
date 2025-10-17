/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:53:31 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/06 18:53:31 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "run_map.h"

void	handle_close_utils(cordinat_map_infos *game)
{
	mlx_destroy_image(game->minilibx, game->images->exit[0]);
	mlx_destroy_image(game->minilibx, game->images->exit[1]);
	mlx_destroy_image(game->minilibx, game->images->exit[2]);
	mlx_destroy_image(game->minilibx, game->images->floor);
	mlx_destroy_image(game->minilibx, game->images->wall);
	mlx_destroy_image(game->minilibx, game->images->collectible);
	mlx_destroy_image(game->minilibx, game->images->player[0]);
	mlx_destroy_image(game->minilibx, game->images->player[1]);
	mlx_destroy_image(game->minilibx, game->images->player[2]);
	mlx_destroy_image(game->minilibx, game->images->player[3]);
	mlx_destroy_window(game->minilibx, game->window);
	mlx_destroy_display(game->minilibx);
	return ;
}
int	handle_close(cordinat_map_infos *game)
{
	t_list	*temp;

	while (game->map_content)
	{
		temp = game->map_content->next;
		free(game->map_content->content);
		free(game->map_content);
		game->map_content = temp;
	}
	handle_close_utils(game);
	exit(0);
}
int handle_key(int keycode, cordinat_map_infos *player)
{
	if (keycode == 65307)
		handle_close(player);
	else if (keycode == 119 || keycode == 65362)
		move_player(player, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(player, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(player, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(player, 1, 0);
	return (0);
}

