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
# include "../../library/Libft/libft.h"
# include "../../library/minilibx-linux/mlx.h"
# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

typedef struct w_mng
{
	void				*minilibx;
	void				*window;
	int					w;
	int					h;
	int					empty;
}	t_window_management;

typedef struct txtrs
{
	void	*wall;
	void	*floor;
	void	*player[1];
	void	*collectible;
	void	*exit[3];
	int		index;
}	t_textures;

typedef struct put_images
{
	int	x;
	int	y;
}	t_put_img;
int		error_messages(int error);
t_list	*save_map_in_linked_list(t_list *map, int fd);
void	window_initilaze(t_list *map, t_window_management	*win);
int		calculate_width_or_height(t_list *map, char mode);
int		fill_map_with_images(t_window_management *win, t_textures *image);
int		put_images_to_map(t_window_management *win,
			t_list *map, t_textures *image);
void	put_all_images(t_window_management *win, t_textures *image,
			t_list	*map, int length);
void	put_all_images_utils(t_window_management *win, t_textures *image,
			t_put_img *cordinat, char *line);
void	clean_if_have_image_error(t_list *map, t_textures *image,
			t_window_management *win);
void	clean_images(t_textures *images, t_window_management *win);
#endif