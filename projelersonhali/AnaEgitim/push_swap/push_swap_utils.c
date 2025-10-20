/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:39:05 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/20 22:39:05 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arrays_int(t_arrays *push_swap, int argc, char **argv)
{
	int	i;

	i = 1;
	push_swap->int_array = malloc(sizeof(int) * argc);
	if (!push_swap->int_array)
		return ;
	while (i < argc)
	{
		push_swap->int_array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	push_swap->int_array[i - 1] = '\0';
	return ;
}
