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
#include "../../library/ft_printf/ft_printf.h"
int	find_first_clb_amount(cordinat_map_infos *clb)
{
	t_list *traversal;
	int		amount_of_clb;
	char	*line;
	int		x;

	//ft_printf("GIRDIM");
	amount_of_clb = 0;
	traversal = clb->map_content;
	while (traversal)
	{
		line = traversal->content;
		x = 0;
		//ft_printf("%d",clb->map_length);
		while (x < clb->map_length)
		{
			if (line[x] == 'C')
				amount_of_clb++;
			//ft_printf("%d",amount_of_clb);
			x++;
		}
		traversal = traversal->next;
	}
	return (amount_of_clb);
}
int	check_is_wall_collectible(cordinat_map_infos *map, int x, int y, char mode)
{
	char	*line;
	t_list	*traversal;
	int		line_number;

	line_number = 0;
	traversal = map->map_content;
	if (mode == 'C')
		y = 0;
	while (line_number < (map->y + y))
	{
		line_number++;
		traversal = traversal->next;
	}
	line = traversal->content;
	if (mode == 'C' && line[map->x] == 'C')
		return (1);
	if (mode == '1' && line[map->x + x] == '1')
		return (1);
	return (0);
}
int	find_exits_cordinates(cordinat_map_infos *exit, char mode)
{
	t_list *traversal;
	char	*line;
	int		x;
	int		y;

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
