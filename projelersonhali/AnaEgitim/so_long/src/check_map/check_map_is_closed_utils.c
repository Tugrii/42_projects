/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:39:05 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/04 17:26:48 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/Libft/libft.h"

int	check_last_and_initial(t_list	*traversal, int length_line)
{
	char	*line;
	int 	mode;
	int		i;
	
	i = 0;
	mode = 0;
	line = traversal->content;
	if (traversal->next)
		mode = 1;		
	while (i < length_line - mode)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
int check_interval_line(t_list	*traversal, int line_length)
{
	char	*line;
	int		mode;

	line = (traversal->content);
	if (traversal->next)
		mode = 2;
	else
		mode = 1;
	if (line[0] == '1' && line[line_length - mode] == '1')
		return (1);
	return (0);
}
