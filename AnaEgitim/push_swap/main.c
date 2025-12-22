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

int main (int argc, char **argv)
{
	t_push_swap	push_swap;

	if (check_status(argc, argv, '1'));
		push_swap.splitted_arguments = split_the_arguments(argv, argc);
	else
		return (print_error_int("Error\n"));
	if (check_status(push_swap.splitted_arguments, '2'))
		push_swap.list = convert_tointlinkedlist(push_swap.splitted_arguments);
	if (!check_is_there_duplicate(&(push_swap.list)))
		return (start_to_execute("To be continue..."));
	return (clean_and_exit(&push_swap, 1, "Error\n"));
}
