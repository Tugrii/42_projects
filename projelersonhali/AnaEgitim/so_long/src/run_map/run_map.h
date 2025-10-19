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

#ifndef RUN_MAP_H
# define RUN_MAP_H
# include "../../library/Libft/libft.h"
# include "../create_map/create_map.h"

typedef struct infos
{
	int			x;
	int			y;
	int			exit_x;
	int			exit_y;
	t_list		*map_content;
	char		**map;
	int			*counters;
	int			map_length;
	int			map_heigth;
	int			collectibles_amount;
	int			movements_amount;
	void		*minilibx;
	void		*window;
	t_textures	*images;
}	t_cordinat_map_infos;
int					run_map(t_list *map, t_window_management *win,
						t_textures *images);
int					move_player(t_cordinat_map_infos *player, int x, int y);
int					find_exits_cordinates(t_cordinat_map_infos *exit,
						char mode);
int					check_is_wall_collectible(t_cordinat_map_infos *map,
						int x, int y);
int					handle_key(int keycode, t_cordinat_map_infos *player);
void				find_initial_position(t_cordinat_map_infos *player);
int					find_first_clb_amount(t_cordinat_map_infos *clb);
t_window_management	take_the_struct(t_cordinat_map_infos *ptr);
int					handle_close(t_cordinat_map_infos *game);
int					check_is_door(t_cordinat_map_infos *player, int x, int y);
#endif