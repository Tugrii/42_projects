/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:29:14 by tgeler            #+#    #+#             */
/*   Updated: 2025/08/20 17:29:14 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		is_there_a_new_line(char *string, int bytes_read, int i, char mode);
char	*divide_the_stash(char **line, char **stash);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*last_stash_controls(char **stash, char **line);
void	fill_it(char *dst, char *src, int j, int i);
void	add_to_stash(char **stash, char *buffer, int bytes_read);
void	fill_new_stash(char *new_stash, char *stash, int index, int length);
int		fill_buffer(char **stash, char **line, int fd);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
#endif
