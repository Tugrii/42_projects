/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initilaze_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:45:01 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/01 17:45:01 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/Libft/libft.h"

int	calculate_width_or_height(t_list *map, char mode)
{
	t_list	*traversal;
	int		width;
	int		length;

	width = 0;
	traversal = map;
	if (!traversal)
		return (0);
	if (mode == 'l')
	{
		length = ft_strlen(traversal->content) - 1;
		return (length);
	}
	while (traversal)
	{
		width++;
		traversal = traversal->next;
	}
	return (width);
}
