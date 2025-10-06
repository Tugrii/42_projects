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
int handle_key(int keycode, cordinat_player *player);
int	move_player(t_list *map, cordinat_player *ptr, int x, int y);
int	run_map(t_list *map, window_management *win);
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