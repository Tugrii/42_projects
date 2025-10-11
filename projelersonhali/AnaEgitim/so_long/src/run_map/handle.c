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

int	handle_close(cordinat_map_infos *game)
{
	t_list	*traversal;
	t_list	*tmp;

	traversal = game->map_content;
	while (traversal)
	{
		tmp = traversal->next;
		free(traversal);
		traversal = tmp;

	}
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

