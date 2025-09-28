/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:37:00 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/28 17:37:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_MAP_H
# define CREATE_MAP_H
#include "../../library/ft_printf/ft_printf.h"
#include "../../library/Libft/libft.h"
int	error_meages(int error);
t_list *save_map_in_linked_list(t_list *map, int fd);
int	window_initilaze();
#endif