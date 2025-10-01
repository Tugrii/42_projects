/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:25:42 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/01 18:18:06 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int		fd;
	t_list	*map;
	window_management win;
	
	if (argc != 2)
		return (error_mesages(1));
	fd = open(argv[1],O_RDONLY,0777);
	if (fd < 0)
		return (error_mesages(2));
	if (check_file_has_valid_name(argv[1]) == 0)
		return (error_mesages(3));
	map = save_map_in_linked_list(&map, fd);
	if (check_status(map) == 0)
		return (error_mesages(4));
	win = window_initilaze(map);
	fill_map_with_images(&win);
	close (fd);
}
