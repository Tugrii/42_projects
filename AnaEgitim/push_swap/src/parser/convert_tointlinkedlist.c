/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tointlinkedlist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"

t_list	*convert_tointlinkedlist(char **str)
{
	int		i;
	t_list	*int_list;

	i = 0;
	int_list = NULL;
	while (str[i])
	{
		ft_lstadd_back(&int_list, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	return (int_list);
}
