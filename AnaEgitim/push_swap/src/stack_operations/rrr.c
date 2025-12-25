/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:20:17 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/25 14:20:17 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	rrr(t_list **list1, t_list **list2)
{
	if (!((list1 && (*list1) && ((*list1)->next))
		|| (list2 && (*list2) && ((*list2)->next))))
			return ;
	rra(list1, '0');
	rrb(list2, '0');
	ft_printf("rrr\n");
	return ;
}
