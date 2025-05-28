/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:07:56 by tgeler            #+#    #+#             */
/*   Updated: 2025/02/23 15:11:15 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	comb[10];
	int		i;

	if (n < 1 || n > 9)
		return ;
	i = -1;
	while (++i < n)
		comb[i] = i + '0';
	while (1)
	{
		write(1, comb, n);
		if (comb[0] == '9' - n + 1 && comb[n - 1] == '9')
			break ;
		write(1, ", ", 2);
		i = n;
		while (--i >= 0 && comb[i] == '9' - (n - 1 - i))
			;
		if (i < 0)
			break ;
		comb[i]++;
		while (++i < n)
			comb[i] = comb[i - 1] + 1;
	}
}
