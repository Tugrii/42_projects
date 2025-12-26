/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_STATUS_H
# define CHECK_STATUS_H
# include "../../Libft/libft.h"

void	arguments_controller(int argc, int argument_limit);
int		check_all_are_number(char **argv);
int		check_is_over_limit(char **argv);
int		check_is_there_duplicate(t_list *list);
int		check_status(int argc, char **argv, char step);
size_t	specilazed_control(char *str);
int		is_sorted(t_list *stack);
#endif