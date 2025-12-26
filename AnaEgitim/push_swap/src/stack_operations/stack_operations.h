/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H
# include "../../Libft/libft.h"

void	pa(t_list **list1, t_list **list2);
void	pb(t_list **list1, t_list **list2);
void	ra(t_list **list, char mode);
void	rb(t_list **list, char mode);
void	rr(t_list **list1, t_list **list2);
void	rra(t_list **list, char mode);
void	rrb(t_list **list, char mode);
void	rrr(t_list **list1, t_list **list2);
void	sa(t_list **list, char mode);
void	sb(t_list **list, char mode);
void	ss(t_list **list1, t_list **list2);
#endif