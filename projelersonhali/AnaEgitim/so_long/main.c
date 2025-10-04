/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:25:42 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/04 23:11:19 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int		fd;
	t_list	*map;
	window_management win;
	
	map = NULL;
	if (argc != 2)
		return (error_messages(1));
	fd = open(argv[1],O_RDONLY,0777);
	if (fd < 0)
		return (error_messages(2));
	if (check_file_has_valid_name(argv[1]) == 0)
		return (error_messages(3));
	map = save_map_in_linked_list(map, fd);
	if (check_status(map) == 0)
		return (error_messages(4));
	window_initilaze(map, &win);
	if (!win.minilibx || !win.window)
	{
    	ft_printf("mlx_init or mlx_new_window failed");
    	exit(1);
	}
	put_images_to_map(&win, map);
	mlx_loop(win.minilibx);
	close (fd);
	return (0);
}
