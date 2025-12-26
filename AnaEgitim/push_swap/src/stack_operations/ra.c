/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:19:47 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/25 14:19:47 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	ra(t_list **list, char mode)
{
	t_list	*second;
	t_list	*traversal;
	t_list	*first;

	if (!list || !(*list) || !(*list)->next)
		return ;
	second = (*list)->next;
	first = (*list);
	traversal = second;
	while (traversal->next)
		traversal = traversal->next;
	traversal->next = first;
	first->next = NULL;
	(*list) = second;
	if (mode == '1')
		ft_printf("ra\n");
	return ;
}
