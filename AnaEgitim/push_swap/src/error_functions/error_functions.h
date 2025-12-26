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
# include "../../Libft/libft.h"
# include "../exit_with_clean_way/exit_with_clean_way.h"

void	print_error_exit(char *msg);
int		print_error_int(char *msg);
#endif