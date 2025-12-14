/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:36:12 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 17:36:12 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/Libft/libft.h"

int	error_messages(int error)
{
	if (error == 1)
		ft_printf("Error!\nThere is no map! to build the game!\n");
	if (error == 2)
		ft_printf("Error!\nFd is not aplicable\n");
	if (error == 3)
		ft_printf("Error!\nMap has not valid name!\n");
	if (error == 4)
		ft_printf("Error!\nMap is not valid!\n");
	if (error == 5)
	{
		ft_printf("Error!\nmlx_init or mlx_new_window failed\n");
		exit(1);
	}
	return (0);
}
