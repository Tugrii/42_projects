/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	close_all_fd(int fd1, int fd2, int fd3, int fd4)
{
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return ;
}

static void	lets_work_the_child(t_pipex *pipex, int input_fd,
		int output_fd, char path_no)
{
	if (dup2(input_fd, 0) == -1)
		clean_and_exit(pipex, 1, "Error!\nDup2 input failed!\n", 2);
	if (dup2(output_fd, 1) == -1)
		clean_and_exit(pipex, 1, "Error!\nDup2 output failed!\n", 2);
	close_all_fd(pipex->end[0], pipex->end[1], input_fd, output_fd);
	if (path_no == '1')
		if (execve(pipex->path1, pipex->splitted_cmd1, pipex->envp) == -1)
			clean_and_exit(pipex, 1, "Error!\nExecv for infile failed!\n", 2);
	if (path_no == '2')
		if (execve(pipex->path2, pipex->splitted_cmd2, pipex->envp) == -1)
			clean_and_exit(pipex, 1, "Error!\nExecv for outfile failed!\n", 2);
	return ;
}

int	start_to_execute(t_pipex *pipex, char **argv,)
{
	int	input_fd;
	int	output_fd;

	input_fd = open(argv[1], O_RDONLY);
	output_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (input_fd == -1 || output_fd == -1)
		clean_and_exit(pipex, 1, "Error!\nfd(s) is not aplicable!\n", 2);
	if (pipe(pipex->end) == -1)
		clean_and_exit(pipex, 1, "Error!\nPipe could'nt created!\n", 2);
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		clean_and_exit(pipex, 1, "Error!\nChild:1 could'nt created!\n", 2);
	else if (pipex->pid1 == 0)
		lets_work_the_child(pipex, input_fd, pipex->end[1], '1');
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		clean_and_exit(pipex, 1, "Error!\nChild:2 could'nt created!\n", 2);
	else if (pipex->pid2 == 0)
		lets_work_the_child(pipex, pipex->end[0], output_fd, '2');
	close_all_fd(pipex->end[0], pipex->end[1], input_fd, output_fd);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	return (clean_and_exit(pipex, 0, NULL, 1));
}
