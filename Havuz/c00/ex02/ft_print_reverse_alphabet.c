/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:36:31 by tgeler            #+#    #+#             */
/*   Updated: 2025/02/23 15:36:35 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	ascii;

	i = 122;
	while (i >= 97)
	{
		ascii = (char)i;
		write(1, &ascii, 1);
		i--;
	}
}
