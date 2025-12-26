/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:20:10 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:35:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	rra(t_list **list, char mode)
{
	t_list	*traversal1;
	t_list	*traversal2;

	if (!list || !(*list) || !((*list)->next))
		return ;
	traversal1 = (*list);
	traversal2 = (*list);
	while (traversal1->next)
		traversal1 = traversal1->next;
	while ((traversal2->next)->next)
		traversal2 = traversal2->next;
	traversal2->next = NULL;
	traversal1->next = (*list);
	(*list) = traversal1;
	if (mode == '1')
		ft_printf("rra\n");
	return ;
}
