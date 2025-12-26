/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:19:43 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/25 14:19:43 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	pb(t_list **list1, t_list **list2)
{
	t_list	*list1_first;
	t_list	*list2_first;
	t_list	*temp;

	if (!list1 || !*(list1))
		return ;
	list1_first = *list1;
	temp = (*list1)->next;
	list2_first = *list2;
	list1_first->next = list2_first;
	*(list1) = temp;
	*(list2) = list1_first;
	ft_printf("pb\n");
	return ;
}
