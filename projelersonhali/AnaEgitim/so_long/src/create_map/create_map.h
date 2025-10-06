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
#include "../../library/get_next_line/get_next_line.h"
# ifndef	TILE_SIZE
#  define TILE_SIZE 32
# endif
typedef struct w_mng
{
	void	*minilibx;
	void	*window;
	unsigned int		width;
	unsigned int		length;
	int		empty;
}window_management;
typedef struct txtrs
{
	void	*wall;
	void	*floor;
	void	*player[4];
	void	*collectible;
	void	*exit;
}textures;
typedef struct put_images
{
	int x;
	int y;
}put_img;
int	error_messages(int error);
t_list *save_map_in_linked_list(t_list *map, int fd);
void window_initilaze(t_list *map, window_management	*win);
int	calculate_width_or_height(t_list *map, char mode);
textures fill_map_with_images(window_management *win);
int	put_images_to_map(window_management *win, t_list *map);
void	put_all_images(window_management *win, textures *image, t_list	*map, int length);
void	put_all_images_utils(window_management *win, textures *image, put_img *cordinat, char *line);
#endif