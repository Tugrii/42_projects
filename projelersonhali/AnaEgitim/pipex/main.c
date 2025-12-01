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

	if (argc != 5)
		return (print_error_int("Argument count is not 4!\n"));
	paths = path_finder(envp);
	path1 = path_creater(paths, argv[2]);
	path2 = path_creater(paths, argv[3]);
	if (!(path1 && path2))
		return (free_memory());
}
