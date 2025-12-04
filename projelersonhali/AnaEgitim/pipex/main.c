/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/11/30 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	char	**paths;
	t_pipex	pipex;

	pipex.path1 = NULL;
	pipex.path2 = NULL;
	if (argc != 5)
		return (print_error_int("Argument count is not 4!\n"));
	if (!split_the_commands(pipex.(&splitted_cmd1), argv[2], pipex.(&splitted_cmd2), argv[3]))
		return (exit_with_clean_way1(pipex.splitted_cmd1, pipex.splitted_cmd2, 2));
	paths = path_finder(envp);
	pipex.path1 = path_creater(paths, splitted_cmd1[0]);
	pipex.path2 = path_creater(paths, splitted_cmd2[0]);
	if ((!pipex.path1 || !pipex.path2 || !pipex.paths))
	{
		exit_with_clean_way1(pipex.splitted_cmd1, pipex.splitted_cmd2, 1);
		return (exit_with_clean_way2(paths, pipex.path1, pipex.path2, 2));
	}
	return (start_to_execute(&pipex, envp, argv));
}
