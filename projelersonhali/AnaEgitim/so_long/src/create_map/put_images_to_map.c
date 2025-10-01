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

textures fill_map_with_images(window_management *win)
{
	textures	image;
	int			img_size;

	img_size = 32;
	image.wall = mlx_xpm_file_to_image(win, "../../textures/wall.xpm", &img_size, &img_size);
	image.wall = mlx_xpm_file_to_image(win, "../../textures/wall.xpm", &img_size, &img_size);
	image.wall = mlx_xpm_file_to_image(win, "../../textures/wall.xpm", &img_size, &img_size);
}