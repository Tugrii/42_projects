/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tointlinkedlist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:25:53 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*convert_tointlinkedlist(char **str)
{
	int		i;
	t_list	*int_list;
	int		*num;

	i = 0;
	int_list = NULL;
	while (str[i])
	{
		num = malloc(sizeof(int));
		*num = ft_atoi(str[i]);
		ft_lstadd_back(&int_list, ft_lstnew(num));
		i++;
	}
	return (int_list);
}
