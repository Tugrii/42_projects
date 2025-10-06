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

int handle_key(int keycode, cordinat_map_infos *player)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119)
		move_player(player, 0, -1);
	else if (keycode == 115)
		move_player(player, 0, 1);
	else if (keycode == 97)
		move_player(player, -1, 0);
	else if (keycode == 100)
		move_player(player, 1, 0);
	return (0);
}
