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

#include "create_map.h"

void	put_all_images_utils(t_window_management *win, t_textures *image,
		t_put_img *cordinat, char *line)
{
	if (line[cordinat->x] == '0')
		mlx_put_image_to_window(win->minilibx, win->window, image->floor,
			(cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	if (line[cordinat->x] == '1')
		mlx_put_image_to_window(win->minilibx, win->window, image->wall,
			(cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	if (line[cordinat->x] == 'C')
		mlx_put_image_to_window(win->minilibx, win->window, image->collectible,
			(cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	if (line[cordinat->x] == 'E')
		mlx_put_image_to_window(win->minilibx, win->window, image->exit[1],
			(cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	if (line[cordinat->x] == 'P')
	{
		mlx_put_image_to_window(win->minilibx, win->window, image->player[0],
			(cordinat->x) * TILE_SIZE, (cordinat->y) * TILE_SIZE);
	}
	return ;
}

void	put_all_images(t_window_management *win, t_textures *image,
		t_list	*map, int length)
{
	t_list		*traversal;
	char		*line;
	t_put_img	cordinat;

	traversal = map;
	cordinat.y = 0;
	length -= 1;
	while (traversal)
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

int	fill_map_with_images(t_window_management *win, t_textures *image)
{
	int			img_size;

	img_size = 32;
	image->wall = mlx_xpm_file_to_image(win->minilibx,
			"./textures/wall.xpm", &img_size, &img_size);
	image->collectible = mlx_xpm_file_to_image(win->minilibx,
			"./textures/collectible.xpm", &img_size, &img_size);
	image->floor = mlx_xpm_file_to_image(win->minilibx,
			"./textures/floor.xpm", &img_size, &img_size);
	image->exit[0] = mlx_xpm_file_to_image(win->minilibx,
			"./textures/exit_open.xpm", &img_size, &img_size);
	image->exit[1] = mlx_xpm_file_to_image(win->minilibx,
			"./textures/exit_close.xpm", &img_size, &img_size);
	image->exit[2] = mlx_xpm_file_to_image(win->minilibx,
			"./textures/exit_close_char.xpm", &img_size, &img_size);
	image->player[0] = mlx_xpm_file_to_image(win->minilibx,
			"./textures/char-_1_.xpm", &img_size, &img_size);
	if (image->wall && image->collectible && image->floor
		&& image->exit[0] && image->exit[1]
		&& image->exit[2] && image->player[0])
		return (1);
	return (0);
}

int	put_images_to_map(t_window_management *win, t_list *map, t_textures *image)
{
	int			line_length;

	line_length = ft_strlen(map->content);
	if (fill_map_with_images(win, image))
	{
		put_all_images(win, image, map, line_length);
		return (1);
	}
	ft_printf("Error!\nProblem occured when uplouding images!\n");
	clean_if_have_image_error(map, image, win);
	return (0);
}
