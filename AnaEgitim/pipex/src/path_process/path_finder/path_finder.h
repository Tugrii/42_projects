/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDER_H
# define PATH_FINDER_H
# include "../../../library/Libft/libft.h"
# include "../../error_functions/error_functions.h"
# include "../path_process.h"
# include "../../exit_with_clean_way/exit_with_clean_way.h"

void	split_the_commands(t_pipex *pipex);
char	**path_finder(char **str, t_pipex *pipex);
#endif
