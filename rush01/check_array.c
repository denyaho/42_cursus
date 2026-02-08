/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:42:54 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/14 12:51:43 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_view_row_top(int array[][4], int view[])
{
	int	row;
	int	col;
	int	tmp;
	int	cnt;

	col = 0;
	while (col < 4)
	{
		cnt = 0;
		tmp = 0;
		row = 0;
		while (row < 4)
		{
			if (tmp < array[row][col])
			{
				tmp = array[row][col];
				cnt++;
			}
			row++;
		}
		if (cnt != view[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_view_row_bottom(int array[][4], int view[])
{
	int	row;
	int	col;
	int	tmp;
	int	cnt;

	col = 0;
	while (col < 4)
	{
		cnt = 0;
		tmp = 0;
		row = 4 - 1;
		while (row >= 0)
		{
			if (tmp < array[row][col])
			{
				tmp = array[row][col];
				cnt++;
			}
			row--;
		}
		if (cnt != view[4 + col])
			return (0);
		col++;
	}
	return (1);
}

int	check_view_col_left(int array[][4], int view[])
{
	int	row;
	int	col;
	int	tmp;
	int	cnt;

	row = 0;
	while (row < 4)
	{
		cnt = 0;
		tmp = 0;
		col = 0;
		while (col < 4)
		{
			if (tmp < array[row][col])
			{
				tmp = array[row][col];
				cnt++;
			}
			col++;
		}
		if (cnt != view[2 * 4 + row])
			return (0);
		row++;
	}
	return (1);
}

int	check_view_col_right(int array[][4], int view[])
{
	int	row;
	int	col;
	int	tmp;
	int	cnt;

	row = 0;
	while (row < 4)
	{
		cnt = 0;
		tmp = 0;
		col = 4 - 1;
		while (col >= 0)
		{
			if (tmp < array[row][col])
			{
				tmp = array[row][col];
				cnt++;
			}
			col--;
		}
		if (cnt != view[3 * 4 + row])
			return (0);
		row++;
	}
	return (1);
}

int	check_view(int array[][4], int view[])
{
	if (!check_view_row_top(array, view))
		return (0);
	if (!check_view_row_bottom(array, view))
		return (0);
	if (!check_view_col_left(array, view))
		return (0);
	if (!check_view_col_right(array, view))
		return (0);
	return (1);
}
