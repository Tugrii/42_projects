/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/11/30 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

# include "execute.h"

int	start_to_execute(t_pipex *pipex, char **envp, char **argv)
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY, 0777);
	
}