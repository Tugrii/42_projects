/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "../../push_swap.h"
# include "../../Libft/libft.h"
# include "../stack_operations/stack_operations.h" 

void	radix_sort(t_list **stack_a, t_list **stack_b, int size);
void	simple_sort(t_list **stack_a, t_list **stack_b, int size);
void	start_to_execute(t_push_swap *push_swap);
#endif
