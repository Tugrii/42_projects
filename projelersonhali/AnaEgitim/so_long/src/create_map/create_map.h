/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:37:00 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 17:37:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_MAP_H
# define CREATE_MAP_H
#include "../../library/ft_printf/ft_printf.h"
#include "../../library/Libft/libft.h"
#include "../../library/minilibx-linux/mlx.h"
# ifndef	TILE_SIZE
#  define TILE_SIZE 32
# endif
typedef struct w_mng
{
	void	*minilibx;
	void	*window;
	int		width;
	int		length;
}window_management;
typedef struct txtrs
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}textures;
int	error_meages(int error);
t_list *save_map_in_linked_list(t_list *map, int fd);
window management window_initilaze(t_list *map);
int	calculate_width_or_height(t_list *map, char mode);
textures fill_map_with_images(window_management *win);
#endif