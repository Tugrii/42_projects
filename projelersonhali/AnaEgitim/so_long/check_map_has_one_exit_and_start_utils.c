/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_one_exit_and_start_utils.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:34:53 by tgeler            #+#    #+#             */
/*   Updated: 2025/09/24 19:54:57 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/Libft/libft.h"

int	exit_start_counter(t_list *traversal, char mode)
{
	char	*adress_catcher;
	int		number_of_character;

	number_of_character = 0;
	adress_catcher = (traversal->content);
	while (ft_strchr(adress_catcher, mode))
	{
		adress_catcher = ft_strchr(adress_catcher, mode);
		number_of_character++;
	}
	return (number_of_character);
}
