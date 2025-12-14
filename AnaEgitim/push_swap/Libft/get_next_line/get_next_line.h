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

void	fill_new_stash(char *new_stash, char *src, int start, int length);
char	*build_new_malloc_for_stash(char **stash, char *buffer, int bytes_read);
char	*add_to_stash(char **stash, char *buffer, int bytes_read);
char	*fill_buffer(char **stash, char **line, int fd);
char	*get_next_line(int fd);
char	*last_stash_controls(char **stash, char **line,
			char **buffer, int bytes_read);
size_t	gnl_strlen(const char *str);
void	fill_it_gnl(char *dst, char *src, int j, int i);
char	*divide_the_stash(char **line, char **stash);
int		is_there_a_new_line(char *string, int bytes_read, int i, char mode);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif