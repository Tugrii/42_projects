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
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	if (fd3 != -1)
		close(fd3);
	if (fd4 != -1)
		close(fd4);
}

static void	lets_work_the_child_utils(t_pipex *pipex, char child_no)
{
	if (child_no == '1')
	{
		close_all_fd(pipex->end[0], pipex->end[1], pipex->input_fd,
			pipex->output_fd);
		if (execve(pipex->path1, pipex->splitted_cmd1, pipex->envp) == -1)
			clean_and_exit(pipex, 1, "Error! about execve for child1:");
	}
	if (child_no == '2')
	{
		close_all_fd(pipex->end[0], pipex->end[1], pipex->input_fd,
			pipex->output_fd);
		if (execve(pipex->path2, pipex->splitted_cmd2, pipex->envp) == -1)
			clean_and_exit(pipex, 1, "Error! about execve for child2:");
	}
}

static void	lets_work_the_child(t_pipex *pipex, pid_t pid, char child_no,
				char *infile_name)
{
	if (pid == 0)
	{
		if (child_no == '1')
		{
			if (pipex->input_fd == -1)
				clean_and_exit(pipex, 1, infile_name);
			if (!pipex->path1)
				command_not_found(pipex->splitted_cmd1[0], pipex);
			if (dup2(pipex->input_fd, 0) == -1 || dup2(pipex->end[1], 1) == -1)
				clean_and_exit(pipex, 1, "Error! about dup2 for child1:");
			lets_work_the_child_utils(pipex, '1');
		}
		if (child_no == '2')
		{
			if (!pipex->path2)
				command_not_found(pipex->splitted_cmd2[0], pipex);
			if (dup2(pipex->end[0], 0) == -1 || dup2(pipex->output_fd, 1) == -1)
				clean_and_exit(pipex, 1, "Error! about dup2 for child2:");
			lets_work_the_child_utils(pipex, '2');
		}
	}
	else
		clean_and_exit(pipex, 1, "Error! Child could'nt created:");
}

int	start_to_execute(t_pipex *pipex, char **argv)
{
	pipex->output_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->output_fd == -1)
		clean_and_exit(pipex, 126, argv[4]);
	pipex->input_fd = open(argv[1], O_RDONLY);
	if (pipe(pipex->end) == -1)
		clean_and_exit(pipex, 1, "Error! Pipe could'nt created!:");
	pipex->pid1 = fork();
	if (pipex->pid1 == 0 || pipex->pid1 == -1)
		lets_work_the_child(pipex, pipex->pid1, '1', argv[1]);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0 || pipex->pid2 == -1)
		lets_work_the_child(pipex, pipex->pid2, '2', NULL);
	close_all_fd(pipex->end[0], pipex->end[1], pipex->input_fd,
		pipex->output_fd);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	return (clean_and_exit(pipex, 0, NULL));
}
