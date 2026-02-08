/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:25:31 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/06 16:04:13 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_element(int i, int j, int col, int row)
{
	void	ft_putchar(char);

	if (i == 1 && (j == 1 || j == row))
		ft_putchar('o');
	else if (i == col && (j == 1 || j == row))
		ft_putchar('o');
	else if (i == 1 || i == col)
		ft_putchar('-');
	else if (j == 1 || j == row)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		i;
	int		j;
	void	ft_putchar(char);

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i++ < y)
	{
		j = 0;
		while (j++ < x)
			print_element(i, j, y, x);
		ft_putchar('\n');
	}
}
