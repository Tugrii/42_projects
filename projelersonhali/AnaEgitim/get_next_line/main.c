/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:54:25 by tgeler            #+#    #+#             */
/*   Updated: 2025/07/30 00:54:25 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
int main ()
{
	int fd = open("tugra", O_CREAT| O_RDWR, 0777);
	/* printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd)); */
	//printf("%s",get_next_line(fd));
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);

	//get_next_line(fd);
	//get_next_line(fd);
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
}
// cc -Wall -Wextra  -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c