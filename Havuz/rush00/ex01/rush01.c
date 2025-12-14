/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:38:14 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/01 18:49:08 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void up(int x) {
    ft_putchar('/');
    int i;

    i = 0;
    while (i < x - 2) {
        ft_putchar('*');
        i++;
    }
    if (x > 1) {
        ft_putchar('\\');
    }
}

void columner(int _x, int _y) {
    int j;
    int i;

    j = 0;
    while (j < _y - 1)
    {
        ft_putchar('*');
        i = 0;
        while (i < _x - 2) {
            ft_putchar(' ');
            i++;
        }
        if (_x > 1) {
            ft_putchar('*');
        }
        ft_putchar('\n');
        j++;
    }
}

void down(int _x) {
    int i;
    
    i = 0;
    if (_x > 1) {
        ft_putchar('\\');
    }
    while (i < _x - 2) {
        ft_putchar('*');
        i++;
    }
    if (_x > 1) {
        ft_putchar('/');
    }
}

void rush(int x, int y) {
    if (x < 2 || y < 1) 
        return ;
    up(x);
    ft_putchar('\n');
    columner(x, y);
    if (y > 1) 
    {
        down(x);
        ft_putchar('\n');
    }
}
