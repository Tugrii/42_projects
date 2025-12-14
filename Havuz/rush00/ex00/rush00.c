/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:03:13 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/01 17:44:49 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	liner(int _i, int _x)
{
	while (_i <= _x)
	{
		if (_i == 1 || _i == _x)
			ft_putchar('o');
		else
			ft_putchar('-');
		_i++;
	}
}

void	columner(int _i, int _x)
{
	while (_i <= _x)
	{
		if (_i == 1 || _i == _x)
			ft_putchar('|');
		else
			ft_putchar(' ');
		_i++;
	}	
}

void	rush(int x, int y)
{
	int		i;
	int		j;

	j = 1;
	while (j <= y)
	{
		if (j == 1 || j == y)
		{
			i = 1;
			liner(i, x);
		}
		else
		{
			i = 1;
			columner(i, x);
		}
		ft_putchar('\n');
		j++;
	}
}
