/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:39:46 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/14 12:51:10 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_view(int array[][4], int view[]);

int	is_valid_number(int row, int col, int num, int array[ ][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		if (array[i][col] == num)
			return (0);
		i++;
	}
	j = 0;
	while (j < col)
	{
		if (array[row][j] == num)
			return (0);
		j++;
	}
	return (1);
}

void	put_array(int row, int col, int array[][4])
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (j == col -1)
			{
				c = array[i][j] + '0';
				write(1, &c, 1);
			}
			else
			{
				c = array[i][j] + '0';
				write(1, &c, 1);
				write(1, " ", 1);
			}
		}
		write(1, "\n", 1);
	}
}

int	array_backtrack(int row, int col, int array[][4], int view[])
{
	int	i;

	if (col == 4)
	{
		if (check_view(array, view))
			return (1);
		return (0);
	}
	if (row == 4)
		return (array_backtrack(0, col + 1, array, view));
	if (array[row][col] != 0)
		return (array_backtrack(row + 1, col, array, view));
	i = 1;
	while (i <= 4)
	{
		if (is_valid_number(row, col, i, array))
		{
			array[row][col] = i;
			if (array_backtrack(row + 1, col, array, view))
				return (1);
			array[row][col] = 0;
		}
		i++;
	}
	return (0);
}

void	skyscrapers(int array[][4], int *view)
{
	if (array_backtrack(0, 0, array, view))
		put_array(4, 4, array);
	else
		write(1, "Error\n", 6);
	return ;
}
