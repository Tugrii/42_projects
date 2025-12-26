/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_to_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:51:53 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/25 14:51:53 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	index_stack(t_list **stack)
{
	t_list	*ptr;
	t_list	*current;

	ptr = *stack;
	while (ptr)
	{
		ptr->index = 0;
		current = *stack;
		while (current)
		{
			if (*(int *)(ptr->content) > *(int *)(current->content))
				ptr->index++;
			current = current->next;
		}
		ptr = ptr->next;
	}
}

void	start_to_execute(t_push_swap *push_swap)
{
	int	size;

	size = ft_lstsize(push_swap->list);
	index_stack(&(push_swap->list));
	if (size <= 5)
		simple_sort(&(push_swap->list), &(push_swap->list_b), size);
	else
		radix_sort((&(push_swap->list)), &(push_swap->list_b), size);
	clean_and_exit(push_swap, 0, NULL);
}
