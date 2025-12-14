/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_if_have_image_error.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:23:25 by tgeler            #+#    #+#             */
/*   Updated: 2025/11/01 16:23:25 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_map.h"

void	clean_images(t_textures *images, t_window_management *win)
{
	if (images->exit[0])
		mlx_destroy_image(win->minilibx, images->exit[0]);
	if (images->exit[1])
		mlx_destroy_image(win->minilibx, images->exit[1]);
	if (images->exit[2])
		mlx_destroy_image(win->minilibx, images->exit[2]);
	if (images->floor)
		mlx_destroy_image(win->minilibx, images->floor);
	if (images->wall)
		mlx_destroy_image(win->minilibx, images->wall);
	if (images->collectible)
		mlx_destroy_image(win->minilibx, images->collectible);
	if (images->player[0])
		mlx_destroy_image(win->minilibx, images->player[0]);
	if (win->window)
		mlx_destroy_window(win->minilibx, win->window);
	if (win->minilibx)
		mlx_destroy_display(win->minilibx);
	if (win->minilibx)
		free(win->minilibx);
	return ;
}

void	clean_if_have_image_error(t_list *map, t_textures *image,
			t_window_management *win)
{
	t_list	*temp;

	while (map)
	{
		temp = map->next;
		free(map->content);
		free(map);
		map = temp;
	}
	clean_images(image, win);
	return ;
}
