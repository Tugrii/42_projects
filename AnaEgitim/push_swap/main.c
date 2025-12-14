/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:14:30 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/20 22:14:30 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_stack a;
	//t_stack b;

	if (check_status(argc, argv) == 0)
		return (-1);
	a.top = NULL;
	//b.top = NULL;
	a.length = argc;
	initilaze_the_a(&a, argv);
}