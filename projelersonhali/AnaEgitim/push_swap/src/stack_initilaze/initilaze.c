/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilaze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:51:53 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/25 14:51:53 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../stack_operations/stack_operations.h"

void	initilaze_the_a(t_stack *a, char **src)
{
	int	i;
	int num;
	t_stack *traversal;
	int	*num_ptr;

	traversal = a;
	i = traversal->length - 1;
	while (i != 0)
	{
		num = ft_atoi(src[i]);
		num_ptr = malloc(sizeof(int));
		if (!num_ptr)
			break ;
		*num_ptr = num;
		ft_lstadd_front(&(traversal->top),ft_lstnew(num_ptr));
		i--;
	}
	return ;
}
