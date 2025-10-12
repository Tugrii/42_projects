/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:37:38 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/13 00:37:38 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initilaze_the_map_copy(t_list	*map)
{
	t_list	*traversal;
	int		x;
	char	*line;

	traversal = map->map_content;
	map->map_length = ft_strlen(traversal) - 1;
	while (traversal)
	{
		x = 0;
		line = traversal->content;
		while (x < (map->map_length))
		{
			if (line[x] != '1')
				line[x] = 'T';
			x++;
		}
		traversal = traversal->next;
	}
	return ;
}