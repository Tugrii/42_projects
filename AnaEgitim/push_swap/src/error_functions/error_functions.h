/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:31:25 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/26 14:26:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_FUNCTIONS_H
# define ERROR_FUNCTIONS_H
# include "../../Libft/libft.h"
# include "../exit_with_clean_way/exit_with_clean_way.h"

void	print_error_exit(char *msg);
int		print_error_int(char *msg);
#endif