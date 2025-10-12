/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:16:06 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/12 19:16:06 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void copy_list(t_list *map, t_list *map_copy)
{
	t_list	*traversal;

	traversal = map;
	map_copy = NULL;
	while (traversal)
	{
		ft_lst_addback(&map_copy, ft_lstnew(traversal->content));
		traversal = traversal->next;
	}
	return ;
}
int	enqueue(void	*content, t_list *reached, t_list *front, t_list *rear)
{
	t_list	*new_node;

	if (front == NULL)
	{
		new_node = ft_lstnew(content);
		front = new_node;
		rear = new_node;
	}
	else
	{
		new_node = ft_lstnew(content);
		ft_lstadd_back(&map_copy, new_node);
		rear->next = new_node;
		rear = new_node;
	}
	return (1);
}
int	dequeue(t_list *reached, t_list *front)
{
	t_list	*temp;

	if (front == NULL)
		return (0);
	temp = front;
	front = front->next;
	free(temp);
	return (1);
}
int	check_valid_path(t_list *map)
{
	cordinat_map_infos *map_copy;
	t_list	*front;
	t_list	*rear;
	t_list	*reached;

	front = NULL;
	rear = NULL;
	copy_list(map, map_copy->map_content);
	initilaze_the_map_copy(map_copy->map_content);
	//buradan devam
}
