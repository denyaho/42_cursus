/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:41:59 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/09/24 10:15:19 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	reflection_map(char **original_map, int **convert_map, t_map element,
		int *square)
{
	int	max;
	int	x_index;
	int	y_index;
	int	x;

	max = find_max_value(original_map, convert_map, element);
	x = x_length(original_map);
	square = find_max_xy(original_map, convert_map, square, element);
	y_index = 0;
	while (y_index < element.number_row)
	{
		x_index = 0;
		while (x_index < x)
		{
			if ((square[0] <= x_index && x_index < square[0] + max)
				&& (square[1] <= y_index && y_index < square[1] + max))
				ft_putchar(element.full);
			else
				ft_putchar(original_map[y_index][x_index]);
			x_index++;
		}
		ft_putchar('\n');
		y_index++;
	}
}

int	*find_max_xy(char **original_map, int **convert_map, int *square,
		t_map element)
{
	int	x_index;
	int	y_index;
	int	x;
	int	max;

	x = x_length(original_map);
	max = find_max_value(original_map, convert_map, element);
	y_index = 0;
	while (y_index < element.number_row)
	{
		x_index = 0;
		while (x_index < x)
		{
			if (convert_map[y_index][x_index] == max)
			{
				square[0] = x_index - max + 1;
				square[1] = y_index - max + 1;
				return (square);
			}
			x_index++;
		}
		y_index++;
	}
	return (square);
}

int	find_max_value(char **original_map, int **convert_map, t_map element)
{
	int	max;
	int	x_index;
	int	y_index;
	int	x;

	x = x_length(original_map);
	y_index = 0;
	max = convert_map[0][0];
	while (y_index < element.number_row)
	{
		x_index = 0;
		while (x_index < x)
		{
			if (max < convert_map[y_index][x_index])
				max = convert_map[y_index][x_index];
			x_index++;
		}
		y_index++;
	}
	return (max);
}
