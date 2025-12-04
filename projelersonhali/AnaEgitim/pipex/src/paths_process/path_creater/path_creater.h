/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creater.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_VALIDITY_H
# define PATH_VALIDITY_H
# include "../../../library/Libft/libft.h"

char	*check_path_validity(char *path, int mode);
char	*path_joiner(char *path, char *cmd);
char	*path_creater(char **paths, char *cmd);

#endif