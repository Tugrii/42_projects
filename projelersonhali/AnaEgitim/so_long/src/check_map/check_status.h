/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:17:56 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/13 00:04:59 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_STATUS_H
# define CHECK_STATUS_H
# include "../run_map/run_map.h"
# include "../../library/Libft/libft.h"
int	check_map_rectangularity(t_list *map);
int	check_map_is_closed(t_list *map);
int	check_map_has_one_exit_and_start(t_list *map);
int check_map_only_contain_valid_characters(t_list *map);
int	check_last_and_initial(t_list	*traversal, int length_line);
int check_interval_line(t_list	*traversal, int line_length);
int	exit_start_counter(t_list *traversal, char mode);
int	check_map_has_at_least_one_clctb(t_list *map);
int	check_valid_path(t_list *map);
int	check_file_has_valid_name(char	*file_name);
int	check_status(t_list *map);
#endif