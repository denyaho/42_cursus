/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albezbor <albezbor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:57:13 by albezbor          #+#    #+#             */
/*   Updated: 2025/09/06 14:19:51 by albezbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j++ < y && x > 0 && y > 0)
	{
		i = 0;
		while (i++ < x)
		{
			if (i != 1 && j != 1 && i != x && j != y)
				ft_putchar(' ');
			else
			{
				if ((i != 1 && i != x) || (j != 1 && j != y))
					ft_putchar('*');
				else if ((i == 1 && j == 1))
					ft_putchar('/');
				else if (i == x && j == y && i != 1 && j != 1)
					ft_putchar('/');
				else
					ft_putchar('\\');
			}
		}
		ft_putchar('\n');
	}
}
