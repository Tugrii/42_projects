/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDER_H
# define PATH_FINDER_H
# include "../../../library/Libft/libft.h"
# include "../../error_functions/error_functions.h"

char	**double_array_join(char **str, char *to_add_str);
char	*path_finder_utils(char **str);
char	**path_finder(char **str);
int		split_the_commands(char ***splitted_cmd1, char *cmd1,
		char ***splitted_cmd2, char *cmd2);
#endif
