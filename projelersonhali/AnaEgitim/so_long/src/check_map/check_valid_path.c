/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:16:06 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/12 19:16:06 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

void	process_neighbor(t_queue *q, int y, int x, t_cordinat_map_infos *infos)
{
	if (y < 0 || y >= infos->map_heigth || x < 0 || x >= infos->map_length)
		return ;
	if (infos->map[y][x] == '1')
		return ;
	if (infos->map[y][x] == 'C')
		infos->counters[0]++;
	else if (infos->map[y][x] == 'E')
		infos->counters[1] = 1;
	infos->map[y][x] = '1';
	enqueue(q, x, y);
}

int	check_valid_path_utils(t_queue *reached, t_cordinat_map_infos *infos)
{
	t_queue_utils	*current_pos;

	enqueue(reached, infos->x, infos->y);
	while (reached->front != NULL)
	{
		current_pos = dequeue(reached);
		infos->x = current_pos->x;
		infos->y = current_pos->y;
		free(current_pos);
		process_neighbor(reached, infos->y - 1, infos->x, infos);
		process_neighbor(reached, infos->y + 1, infos->x, infos);
		process_neighbor(reached, infos->y, infos->x - 1, infos);
		process_neighbor(reached, infos->y, infos->x + 1, infos);
	}
	if (infos->counters[0] == infos->collectibles_amount
		&& infos->counters[1] == 1)
	{
		free(infos->counters);
		free_it(infos->map, infos->map_heigth);
		return (1);
	}
	free(infos->counters);
	ft_printf("The Game is not finishable so map couldnt created!\n");
	free_it(infos->map, infos->map_heigth);
	return (0);
}

int	check_valid_path(t_list *map)
{
	t_cordinat_map_infos	infos;
	t_queue					reached;

	infos.map_content = map;
	infos.counters = malloc(sizeof(int) * 2);
	if (!(infos.counters))
		return (0);
	infos.map_heigth = ft_lstsize(map);
	infos.map_length = ft_strlen(map->content) - 1;
	find_initial_position(&infos);
	find_first_clb_amount(&infos);
	convert_list_to_array(map, &infos);
	if (!(infos.map))
	{
		free(infos.counters);
		return (0);
	}
	reached.front = NULL;
	reached.rear = NULL;
	infos.map[infos.y][infos.x] = '1';
	infos.counters[0] = 0;
	infos.counters[1] = 0;
	return (check_valid_path_utils(&reached, &infos));
}
