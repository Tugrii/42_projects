/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:14:34 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/20 22:14:34 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
typedef struct arrays
{
	int		*int_array;
}t_arrays;
void	fill_arrays_int(t_arrays *push_swap, int argc, char **argv);
#endif