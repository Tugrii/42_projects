/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initilaze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:30:22 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 19:19:16 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../so_long.h"

t_list *save_map_in_linked_list(t_list *map, int fd)
{
	char	*line;
	int		i;
	char	*previous_line;
	
	i = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (i != 0)
			line = get_next_line(fd);
		ft_lstadd_back(&map, ft_lstnew(line));
		free(line);
		i++;
	}
	return (map);
}

int	window_initilaze()
{
	window_management	create_win;
	
	//create_win.width = TILE_SIZE * 
	create_win.minilibx = mlx_init();
	if (!(create_win.minilibx))
		return (-2);
	create_win.window = mlx_new_window(create_win.minilibx, 640, 480, "so_long");
	if (!(create_win.window))
		return (-3);
}
