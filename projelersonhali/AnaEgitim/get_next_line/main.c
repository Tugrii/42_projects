/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:30:33 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/01 02:53:29 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
	int i;

	int fd = open("tugra", O_CREAT| O_RDWR , 0777);
	i = 0;
	char *ptr;

	while (i < 1)
	{
		ptr = get_next_line(fd);
		printf("%s",ptr);
		free(ptr);
		i++ ;
	}

}