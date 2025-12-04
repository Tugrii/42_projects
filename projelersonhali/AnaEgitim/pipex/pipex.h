/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/11/30 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "library/Libft/libft.h"
# include "src/error_functions/error_functions.h"
# include "src/exit_with_clean_way/exit_with_clean_way.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
typedef struct s_pipex
{
	char	**splitted_cmd1;
	char	**splitted_cmd2;
	char	*path1;
	char	*path2;
	char	**argv;
	char	**envp;
	int		end[2];
	pid_t	pid1;
	pid_t	pid2;
}   t_pipex;
#endif