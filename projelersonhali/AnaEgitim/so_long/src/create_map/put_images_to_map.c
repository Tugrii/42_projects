/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_to_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:07:28 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/01 23:07:28 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "create_map.h"

void	put_all_images_utils(window_management *win, textures *image, put_img *cordinat, char *line)
{

	if (line[cordinat->x] == '1')
		mlx_put_image_to_window(win->minilibx , win->window, image->wall, (cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	if (line[cordinat->x] == 'C')
		mlx_put_image_to_window(win->minilibx , win->window, image->collectible, (cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	if (line[cordinat->x] == 'P')
	{
		mlx_put_image_to_window(win->minilibx, win->window,
		image->player[0],
		(cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	}
	return ;
}

void	put_all_images(window_management *win, textures *image, t_list	*map, int length)
{
	t_list	*traversal;
	char	*line;

	put_img		cordinat;
	traversal = map;
	cordinat.y = 0;
	while(traversal)
	{
		line = traversal->content;
		cordinat.x = 0;
		while (cordinat.x < length)
		{
			put_all_images_utils(win, image, &cordinat, line);
			(cordinat.x)++;
		}
		(cordinat.y)++;
		traversal = traversal->next;
	}
	return ;
}
textures fill_map_with_images(window_management *win)
{
	textures	image;
	int			img_size;

	img_size = 32;
	image.wall = mlx_xpm_file_to_image(win->minilibx, "../../textures/wall.xpm", &img_size, &img_size);
	image.collectible = mlx_xpm_file_to_image(win->minilibx, "../../textures/collectible.xpm", &img_size, &img_size);
	image.player[0] = mlx_xpm_file_to_image(win->minilibx, "../../textures/char-_1_.xpm", &img_size, &img_size);
	image.player[1] = mlx_xpm_file_to_image(win->minilibx, "../../textures/char-_2_.xpm", &img_size, &img_size);
	image.player[2] = mlx_xpm_file_to_image(win->minilibx, "../../textures/char-_3_.xpm", &img_size, &img_size);
	image.player[3] = mlx_xpm_file_to_image(win->minilibx, "../../textures/char-_4_.xpm", &img_size, &img_size);
	return (image);
}
int	put_images_to_map(window_management *win, t_list *map)
{
	textures	image;
	int			line_length;

	line_length = ft_strlen(map->content) - 1;
	image = fill_map_with_images(win);
	put_all_images(win, &image, map, line_length);
	return (0);
}
