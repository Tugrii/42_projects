/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:31:25 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_FUNCTIONS_H
# define ERROR_FUNCTIONS_H
# include "../../library/Libft/libft.h"
# include "../path_process/path_process.h"
# include "../exit_with_clean_way/exit_with_clean_way.h"
# include <stdio.h>

void	print_error_exit(char *msg, int exit_type);
int		print_error_int(char *msg);
void	arguments_controller(int argc, int argument_limit);
#endif