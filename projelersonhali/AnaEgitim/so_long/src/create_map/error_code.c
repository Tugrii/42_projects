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

#include "../../library/ft_printf/ft_printf.h"

int	error_messages(int error)
{
	if (error == 1)
		ft_printf("There is no map! to build the game!\n");
	if (error == 2)
		ft_printf("Error occured! that cause by fd is not aplicable\n");
	if (error == 3)
		ft_printf("Error! Map has not valid name!\n");
	if (error == 4)
		ft_printf("Map is not valid!\n");
	return (0);
}
