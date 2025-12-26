/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_there_duplicate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

int	check_is_there_duplicate(t_list *list)
{
	t_list	*node;
	t_list	*traversal;

	traversal = list;
	while (traversal)
	{
		node = list;
		while (node != traversal)
		{
			if (*(int *)(traversal->content) == *(int *)(node->content))
				return (1);
			node = node->next;
		}
		traversal = traversal->next;
	}
	return (0);
}
