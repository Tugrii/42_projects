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

int		is_there_a_new_line(char *buffer, int bytes_read);
char	*divide_the_stash(char *line, char **stash, int i, int length_new_stas);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	fill_it(char *dst, char *src, int length, int j);
int		free_and_rebuild(char **stash, char *new_stash, int length_new_stash);
int		add_to_stash(char **stash, char *buffer, int index, int j);
void	*fill_refill_buffer(int fd, char **buffer, char mode);
int		make_malloc_for_each_stash(char **stash, int bytes_read);
char	*make_malloc_and_fill(char **line, char **stash, int length_to_fill);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
#endif
