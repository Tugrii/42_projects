/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:20:02 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/25 14:20:02 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	rr(t_list **list1, t_list **list2)
{
	if (!((list1 && (*list1) && ((*list1)->next))
			|| (list2 && (*list2) && ((*list2)->next))))
		return ;
	ra(list1, '0');
	rb(list2, '0');
	ft_printf("rr\n");
	return ;
}
