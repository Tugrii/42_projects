/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	push_swap.splitted_arg = NULL;
	push_swap.list = NULL;
	push_swap.list_b = NULL;
	if (check_status(argc, argv, '1'))
	{
		push_swap.splitted_arg = split_the_arguments(argv, argc);
		if (check_status(argc, push_swap.splitted_arg, '2'))
			push_swap.list = convert_tointlinkedlist(push_swap.splitted_arg);
		else
			clean_and_exit(&push_swap, 1, "Error\n");
	}
	else
		return (print_error_int("Error\n"));
	if (!check_is_there_duplicate(push_swap.list))
	{
		if (!is_sorted(push_swap.list))
			start_to_execute(&push_swap);
		else
			clean_and_exit(&push_swap, 0, NULL);
	}
	return (clean_and_exit(&push_swap, 1, "Error\n"));
}
