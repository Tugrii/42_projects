/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:24:58 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/04 17:33:53 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"
#include "../../library/ft_printf/ft_printf.h"

int	check_map_only_contain_valid_characters(t_list *map)
{
	t_list	*traversal;
	char	*line;
	int		length_line;
	int		i;

	traversal = map;
	traversal = traversal->next;
	line = traversal->content;
	length_line = ft_strlen(line);
	while (traversal->next)
	{
		i = 0;
		while (i < (length_line - 1))
		{
			if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
				&& line[i] != 'E' && line[i] != 'P')
				return (0);
			i++;
		}
		traversal = traversal->next;
		line = traversal->content;
	}
	return (1);
}

int	check_map_rectangularity(t_list *map)
{
	int		current_line_length;
	int		previous_line_length;
	t_list	*traversal;
	int		i;

	i = 1;
	traversal = map;
	current_line_length = ft_strlen(traversal->content);
	while (traversal)
	{
		if (i != 1)
			previous_line_length = current_line_length;
		current_line_length = ft_strlen(traversal->content);
		if (!ft_strchr(traversal->content, '\n'))
			previous_line_length -= 1;
		if (i != 1 && (previous_line_length != current_line_length))
		{
			ft_printf("Map is not RECTANGULAR!\n");			
			return (0);
		}
		traversal = traversal->next;
		i++;
	}
	return (1);
}
int	check_map_is_closed(t_list *map)
{
	t_list	*traversal;
	int		truth;
	
	traversal = map;
	while (traversal)
	{
		if ((traversal == map ) || !(traversal->next))
			truth = check_last_and_initial(traversal, ft_strlen(traversal->content));
		else
			truth = check_interval_line(traversal, ft_strlen(traversal->content));
		if (truth == 0)
		{
			ft_printf("Map is not CLOSED!\n");
				return (0);
		}
		traversal = traversal->next;
	}
	return (1);
}
int	check_map_has_one_exit_and_start(t_list *map)
{
	t_list	*traversal;
	int		number_of_exits;
	int		number_of_starts;
	
	number_of_exits = 0;
	number_of_starts= 0;
	traversal = map;	
	while (traversal)
	{
		number_of_exits += exit_start_counter(traversal, 'E');
		number_of_starts += exit_start_counter(traversal, 'P');
		traversal = traversal->next;
	}
	if (number_of_starts != 1)
		ft_printf("Error! Map has %d%s\n",number_of_starts, " STARTS!");
	if (number_of_exits != 1)
		ft_printf("Error! Map has %d%s\n",number_of_exits, " EXITS!");
	if (number_of_starts != 1 || number_of_exits != 1)
		return (0);
	return (1);	
}
int	check_map_has_at_least_one_clctb(t_list *map)
{
	t_list 	*traversal;
	char	*line;

	traversal = map;
	traversal = traversal->next;
	while (traversal->next)
	{
		line = traversal->content;
		line = ft_strchr(line, 'C');
		if (line)
			return (1);
		traversal = traversal->next;
	}
	ft_printf("Error! The map has not even one collectible\n");
	return (0);
}
