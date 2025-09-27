/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:25:42 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/23 21:00:10 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int		fd;
	t_list	*map;
	int		truth;

	if (argc != 2)
	{
		ft_printf("%s","There is no map! to build the game!");
		return (-42);
	}
	fd = open(argv[1],O_RDONLY,0777);
	if (fd < 0)
	{
		perror("Error occured! that cause by fd is not aplicable");
		return (-500);
	}
	map = save_map_in_linked_list(&map, fd);
	truth = check_status(map);
	if (truth == 0)
	{
		ft_printf("Map is not rectangular!");
		return (-450);		
	}
	close (fd);
}
