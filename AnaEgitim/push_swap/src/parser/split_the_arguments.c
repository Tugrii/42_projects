/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_the_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:35:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/12/01 22:35:37 by tgeler           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_the_arguments.h"

char	*cat_the_arguments(char **argv, int argc)
{
	int		i;
	char	*temp1;
	char	*main_string;
	char	*temp2;

	i = 2;
	temp1 = NULL;
	temp2 = NULL;
	main_string = argv[1];
	while (i < argc)
	{
		if (i > 2)
			temp1 = main_string;
		main_string = ft_strjoin(main_string, ' ');
		if (!main_string)
			return (NULL);
		temp2 = main_string;
		main_string = ft_strjoin(main_string, argv[i]);
		if (!main_string)
			return (NULL);
		free (temp2);
		free (temp1);
		i++;
	}
	return (main_string);
}
char	**split_the_arguments(char **argv, int argc)
{
	char	**splitted_arguments;
	char	*non_splitted_arguments;

	non_splitted_arguments = cat_the_arguments(argv, argc);
	if (!non_splitted_arguments)
		return (NULL);
	splitted_arguments = ft_split(non_splitted_arguments);
	if (!splitted_arguments)
		
}
