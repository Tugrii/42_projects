/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_PROCESS_H
# define PATH_PROCESS_H
# include <sys/types.h>

typedef struct s_pipex
{
	char	**splitted_cmd1;
	char	**splitted_cmd2;
	char	*path1;
	char	*path2;
	char	**paths;
	char	argv[2];
	char	**envp;
	int		end[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;
#endif