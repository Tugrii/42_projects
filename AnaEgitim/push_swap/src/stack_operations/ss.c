/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:20:27 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/25 14:20:27 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	ss(t_list **list1, t_list **list2)
{
	if (!((list1 && (*list1) && ((*list1)->next))
			|| (list2 && (*list2) && ((*list2)->next))))
		return ;
	sa(list1, '0');
	sb(list2, '0');
	ft_printf("ss\n");
	return ;
}
