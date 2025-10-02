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

	length = 0;
	traversal = map;
	while (traversal)
	{
		if (!(traversal->next))
			length = ft_strlen(traversal->content);
		width++;
		traversal = traversal->next;
	}
	if (mode == 'l')
		return (length);
	if (mode == 'w')
		return (width);
	return (0);
}
