/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_cal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:45:26 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/09/24 12:48:11 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**convert_char_int(char **map, t_map element, int x)
{
	int	y_index;
	int	x_index;
	int	**convert_map;

	convert_map = (int **)malloc(sizeof(int *) * element.number_row);
	if (!convert_map)
		return (NULL);
	y_index = 0;
	while (y_index < element.number_row)
	{
		convert_map[y_index] = (int *)malloc(sizeof(int) * x);
		x_index = 0;
		while (x_index < x)
		{
			if (map[y_index][x_index] == element.obstacle)
				convert_map[y_index][x_index] = 0;
			else if (map[y_index][x_index] == element.empty)
				convert_map[y_index][x_index] = 1;
			x_index++;
		}
		y_index++;
	}
	return (convert_map);
}

int	**dynamic_cal(int **map, int y, int x)
{
	int	y_index;
	int	x_index;

	y_index = 1;
	x_index = 1;
	while (y_index < y)
	{
		x_index = 1;
		while (x_index < x)
		{
			if (map[y_index][x_index] != 0)
				map[y_index][x_index] = find_min(map, y_index, x_index) + 1;
			x_index++;
		}
		y_index++;
	}
	return (map);
}

int	find_min(int **map, int y, int x)
{
	int	min;

	min = -1;
	if (y > 0 && x > 0)
	{
		min = map[y - 1][x - 1];
		if (min > map[y][x - 1])
			min = map[y][x - 1];
		if (min > map[y - 1][x])
			min = map[y - 1][x];
	}
	return (min);
}

int	search_square(char **map, t_map element)
{
	int	**convert_map;
	int	x;
	int	square_xy[2];

	x = x_length(map);
	convert_map = convert_char_int(map, element, x);
	if (!convert_map)
		return (0);
	convert_map = dynamic_cal(convert_map, element.number_row, x);
	reflection_map(map, convert_map, element, square_xy);
	free_convert_map(convert_map, element);
	return (1);
}

//
// int	main(void)
// {
// 	char	**map;
// 	t_map	element;

// 	element.number_row = 9;
// 	element.empty = '.';
// 	element.obstacle = 'o';
// 	element.full = 'x';
// 	map = (char **)malloc((sizeof(char *) * (element.number_row + 1)));
// 	map[0] = "...........................\0";
// 	map[1] = "....o......................\0";
// 	map[2] = "............o..............\0";
// 	map[3] = "...........................\0";
// 	map[4] = "....o......................\0";
// 	map[5] = "...............o...........\0";
// 	map[6] = "...........................\0";
// 	map[7] = "......o..............o.....\0";
// 	map[8] = "..o.......o................\0";
// 	map[9] = "\0";
// 	if (!(search_square(map, element)))
// 		return (1);
// 	// free_map(map, element);
// 	return (0);
// }
//
