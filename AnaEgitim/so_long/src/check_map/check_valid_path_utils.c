/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:37:38 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/13 00:37:38 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_status.h"

void	free_it(char **map_copy, int height)
{
	int	i;

	i = 0;
	if (!map_copy)
		return ;
	while (i < height && map_copy[i] != NULL)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

void	convert_list_to_array(t_list *map, t_cordinat_map_infos *infos)
{
	t_list	*traversal;
	int		heigth;
	int		i;

	i = 0;
	heigth = ft_lstsize(map);
	traversal = map;
	infos->map = malloc(sizeof(char *) * (heigth + 1));
	if (!(infos->map))
		return ;
	while (traversal && i < heigth)
	{
		infos->map[i] = ft_strdup(traversal->content);
		if (!(infos->map[i]))
		{
			free_it(infos->map, i);
			infos->map = NULL;
			return ;
		}
		i++;
		traversal = traversal->next;
	}
	infos->map[i] = NULL;
	return ;
}

t_queue_utils	*create_queue_node(int x, int y)
{
	t_queue_utils	*new_node;

	new_node = malloc(sizeof(t_queue_utils));
	if (!new_node)
		return (NULL);
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	return (new_node);
}

void	enqueue(t_queue *q, int x, int y)
{
	t_queue_utils	*new_node;

	new_node = create_queue_node(x, y);
	if (!new_node)
		return ;
	if (q->rear == NULL)
	{
		q->front = new_node;
		q->rear = new_node;
	}
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
	return ;
}

t_queue_utils	*dequeue(t_queue *q)
{
	t_queue_utils	*node_to_remove;

	if (q->front == NULL)
		return (NULL);
	node_to_remove = q->front;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	return (node_to_remove);
}
