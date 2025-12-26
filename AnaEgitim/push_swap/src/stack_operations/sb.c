/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:20:25 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:35:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	sb(t_list **list, char mode)
{
	t_list	*first;
	t_list	*second;

	if (!list || !*(list) || !(*list)->next)
		return ;
	first = (*list);
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	(*list) = second;
	if (mode == '1')
		ft_printf("sb\n");
	return ;
}
