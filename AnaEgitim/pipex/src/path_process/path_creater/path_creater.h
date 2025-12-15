/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creater.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_CREATER_H
# define PATH_CREATER_H
# include "../../../library/Libft/libft.h"
# include "../path_process.h"
# include "../../exit_with_clean_way/exit_with_clean_way.h"

char	*path_creater(t_pipex *pipex, char **paths, char *cmd);
#endif