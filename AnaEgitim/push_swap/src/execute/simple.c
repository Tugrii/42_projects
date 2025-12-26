/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	sort_three(t_list **stack_a)
{
	t_list	*head;
	int		top;
	int		mid;
	int		bot;

	head = *stack_a;
	top = head->index;
	mid = head->next->index;
	bot = head->next->next->index;
	if (top > mid && top > bot)
		ra(stack_a, '1');
	else if (mid > top && mid > bot)
		rra(stack_a, '1');
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, '1');
}

static int	get_min_pos(t_list **stack)
{
	t_list	*head;
	int		min_index;
	int		i;

	head = *stack;
	min_index = head->index;
	while (head)
	{
		if (head->index < min_index)
			min_index = head->index;
		head = head->next;
	}
	head = *stack;
	i = 0;
	while (head)
	{
		if (head->index == min_index)
			return (i);
		head = head->next;
		i++;
	}
	return (i);
}

static void	sort_five(t_list **stack_a, t_list **stack_b, int size, int min_pos)
{
	while (size > 3)
	{
		min_pos = get_min_pos(stack_a);
		if (min_pos <= size / 2)
		{
			while (min_pos > 0)
			{
				ra(stack_a, '1');
				min_pos--;
			}
		}
		else
		{
			while (min_pos < size)
			{
				rra(stack_a, '1');
				min_pos++;
			}
		}
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a);
}

void	simple_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, '1');
	}
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, stack_b, size, 0);
}
