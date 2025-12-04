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
	char	*path1;
	char	*path2;
	char	**paths;
	char	**splitted_cmd1;
	char	**splitted_cmd2;

	path1 = NULL;
	path2 = NULL;
	if (argc != 5)
		return (print_error_int("Argument count is not 4!\n"));
	if (!split_the_commands(&splitted_cmd1, argv[2], &splitted_cmd2, argv[3]))
		return (exit_with_clean_way1(splitted_cmd1, splitted_cmd2, NULL, 2));
	paths = path_finder(envp);
	path1 = path_creater(paths, splitted_cmd1[0]);
	path2 = path_creater(paths, splitted_cmd2[0]);
	if ((!path1 || !path2 || !paths))
	{
		exit_with_clean_way1(splitted_cmd1, splitted_cmd2, NULL, 1);
		return (exit_with_clean_way2(paths, path1, path2, 2));
	}
}
