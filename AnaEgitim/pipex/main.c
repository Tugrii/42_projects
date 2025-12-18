/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	pipex.path1 = NULL;
	pipex.path2 = NULL;
	pipex.splitted_cmd1 = NULL;
	pipex.splitted_cmd2 = NULL;
	pipex.paths = NULL;
	pipex.envp = envp;
	pipex.argv[0] = argv[2];
	pipex.argv[1] = argv[3];
	arguments_controller(argc, 4);
	split_the_commands(&pipex);
	pipex.paths = path_finder(envp, &pipex);
	pipex.path1 = path_creater(&pipex, pipex.paths, pipex.splitted_cmd1[0]);
	pipex.path2 = path_creater(&pipex, pipex.paths, pipex.splitted_cmd2[0]);
	return (start_to_execute(&pipex, argv));
}
