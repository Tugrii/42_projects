/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:08:18 by tgeler            #+#    #+#             */
/*   Updated: 2025/07/13 20:08:18 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "Libft/libft.h"

int		ft_printf(const char *type, ...);
int		process1(const char *sub_type, va_list *argument);
int		process2(const char *sub_type, va_list *argument);
void	ft_puthex_fd(unsigned long value, int fd, int is_upper);
int		count_size_of_int(unsigned long value, int previous_value);
int		process3(const char *sub_type, va_list *argument);
void	put_un_int_fd(unsigned int value, int fd);

#endif