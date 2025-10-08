/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:30:42 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/06 19:30:42 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RUN_MAP_H
#define RUN_MAP_H
# include "../../library/Libft/libft.h"
# include "../create_map/create_map.h"
int	run_map(t_list *map, window_management *win);
int	move_player(t_list *map, cordinat_map_infos *player, int x, int y);
int	find_exits_cordinates(cordinat_map_infos *exit, char mode);
int	check_is_wall_collectible(cordinat_map_infos *map, char mode);
int handle_key(int keycode, cordinat_map_infos *player);
void	find_initial_position(cordinat_map_infos *player);
typedef struct infos
{
	int	x;
	int	y;
	t_list *map_content;
	int map_length;
	int	collectibles_amount;
	void *minilibx;
	void *window;
}cordinat_map_infos;

#endif