/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:32:14 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 18:23:43 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "library/minilibx-linux/mlx.h"
# include "library/get_next_line/get_next_line.h"
# include "library/Libft/libft.h"
# include "src/create_map/create_map.h"
# include "src/check_map/check_status.h"
# ifndef	TILE_SIZE
#  define TILE_SIZE 32
# endif
t_list *save_map_in_linked_list(t_list *map, int fd);
typedef struct w_mng
{
	void	*minilibx;
	void	*window;
	int		width;
	int		height;
}window_management;

typedef struct txtrs
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}textures;


#endif