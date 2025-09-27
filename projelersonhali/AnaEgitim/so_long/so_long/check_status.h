/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:17:56 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/24 20:24:51 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_STATUS_H
# define CHECK_STATUS_H

# include "library/Libft/libft.h"
int	check_map_rectangularity(t_list *map);
int	check_map_is_closed(t_list *map);
int	check_map_has_one_exit_and_start(t_list *map);
int	check_not_surrounded(t_list *map);
int check_map_only_contain_valid_characters(t_list *map);
int check_interval_line(t_list *traversal);
int	exit_start_counter(t_list *traversal, char mode);
int	check_map_has_at_least_one_clctb(t_list *map);

#endif