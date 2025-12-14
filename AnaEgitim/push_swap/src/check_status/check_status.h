/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:45:20 by tgeler            #+#    #+#             */
/*   Updated: 2025/10/28 21:45:20 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_STATUS_H
# define CHECK_STATUS_H
# include "../error_messages/error_messages.h"
	int	check_all_are_number(int argc, char **argv);
	int check_is_over_limit(int argc, char **argv);
	int	check_is_there_duplicate(int argc, char **argv);
	int	check_status(int argc, char **argv);
#endif