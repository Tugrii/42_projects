/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:50:17 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/08 17:50:17 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "run_map.h"

window_management take_the_struct(cordinat_map_infos *ptr)
{
	window_management temp;

	temp.minilibx = ptr->minilibx;
	return (temp);
}
