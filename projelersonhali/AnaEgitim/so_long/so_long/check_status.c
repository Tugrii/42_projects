/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:57:46 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/27 22:16:01 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "library/Libft/libft.h"
# include "check_status.h"

int	check_status(t_list *map)
{
	int	truth;
	
	truth = check_map_rectangularity(map); // okay
	if (truth == 1)
		truth = check_map_is_closed(map); // okay
	if (truth == 1)
		truth = check_map_has_one_exit_and_start(map); // okay
	if (truth == 1)
		truth = check_map_has_at_least_one_clctb(map); // okay
	if (truth == 1)
		truth = check_map_only_contain_valid_characters(map); //okay
	if (truth == 1)
		truth = check_not_surrounded(map);
	return (truth);
}
