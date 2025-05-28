/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:12:57 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/04 12:13:15 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 0 || (nb != 2 && nb % 2 == 0) || nb == 1)
		return (2);
	else
	{
		while (i * i <= nb)
		{
			if (nb % i == 0)
				return (2);
			i += 2;
		}
		return (nb);
	}
}

int	ft_find_next_prime(int nb)
{
	if (ft_find_is_prime(nb) == nb)
		return (nb);
	else
	{
		while (!(ft_find_is_prime(nb) == nb))
		{
			if (nb == 1)
				return (2);
			if (nb % 2 == 0)
				nb += 1;
			else
				nb += 2;
		}
		return (nb);
	}
}
