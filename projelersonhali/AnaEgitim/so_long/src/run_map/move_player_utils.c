/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:43:33 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/06 22:43:33 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "run_map.h"

int	find_first_clb_amount(cordinat_map_infos *clb)
{
	t_list *traversal;
	int		amount_of_clb;
	char	*line;
	int		x;

	amount_of_clb = 0;
	traversal = clb->map_content;
	while (traversal)
	{
		line = traversal->content;
		x = 0;
		while (x < (clb->map_length))
		{
			if (line[x] == 'C')
				amount_of_clb++;
			x++;
		}
		traversal = traversal->next;
	}
	clb->collectibles_amount = amount_of_clb;
	return (0);
}
int	check_is_wall_collectible(cordinat_map_infos *map, int x, int y)
{
	char	*line;
	t_list	*traversal;
	int		line_number;

	line_number = 0;
	traversal = map->map_content;
	while (line_number < (map->y + y))
	{
		line_number++;
		traversal = traversal->next;
	}
	line = traversal->content;
	if (line[map->x + x] == '1')
		return (1);
	if (line[map->x + x] == 'C')
	{
		line[map->x + x] = 'X';
		(map->collectibles_amount)--;
	}
	return (-1);
}
int	find_exits_cordinates(cordinat_map_infos *exit, char mode)
{
	t_list *traversal;
	char	*line;
	int		x;
	int		y;

	y = 0;
	traversal = exit->map_content;
	while (traversal)
	{
		line = traversal->content;
		x = 0;
		while (x < exit->map_length)
		{
			if (line[x] == 'E' && mode == 'x')
				return (x);
			if (line[x] == 'E' && mode == 'y')
				return (y);
			x++;
		}
		y++;
		traversal = traversal->next;
	}
	return (0);
}
int	check_is_won(cordinat_map_infos *player, int x, int y)
{
	t_list	*traversal;
	int		line_number;

	line_number = 0;
	traversal = player->map_content;
	while (line_number < (player->y + y))
	{
		line_number++;
		traversal = traversal->next;
	}
	if (((player->y + y) == player->exit_y) && ((player->x + x) == player->exit_x))
	{
		ft_printf("YOU WON THE GAME!\n");
		handle_close(player);
	}
	return (0);
}
