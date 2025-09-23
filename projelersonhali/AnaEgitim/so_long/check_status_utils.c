/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:24:58 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/23 22:04:48 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/Libft/libft.h"

int	check_map_rectangularity(t_list *map)
{
	int		current_line_length;
	int		previous_line_length;
	t_list	*traversal;
	
	traversal = map;
	current_line_length = 0;
	previous_line_length = 0;
	while ((previous_line_length == current_line_length) && traversal)
	{
		previous_line_length = ft_strlen(traversal->content);
		traversal = traversal->next;
		if (traversal)
			current_line_length = ft_strlen(traversal->content);
	}
	if (previous_line_length != current_line_length)
		return (0);
	return (1);
}
int	check_map_is_closed(t_list *map)
{
	t_list	*traversal;
	int		i;
	char	*character_list;
	int		line_length;

	character_list = "0CEP";
	i = 0;
	traversal = map;
	while (traversal)
	{
		if (i == 0 || !(traversal->next))
		{
			if ((ft_strnstr(traversal->content, character_list, ft_strlen(traversal->content))))
				return (0);
		}
		line_length = ft_strlen(traversal->content);
		traversal = traversal->next;
		
		i++;
	}
}
