/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: q <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:42:37 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/09/22 09:45:50 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include <stdio.h>

int	ft_strlen(char *str);
int	is_valid_words(char *buf, int idx);

int	is_valid_first_line(char *buf, t_map *map)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	if (!(buf[0] >= '0' && buf[0] <= '9'))
		return (1);
	while (buf[idx] >= '0' && buf[idx] <= '9')
	{
		size = size * 10 + (buf[idx] - '0');
		idx++;
	}
	if ((buf[idx] != buf[idx + 1]) && (buf[idx] != buf[idx + 2])
		&& (buf[idx + 1] != buf[idx + 2]))
	{
		if (!is_valid_words(buf, idx))
		{
			map->number_row = size;
			map->empty = buf[idx];
			map->obstacle = buf[idx + 1];
			map->full = buf[idx + 2];
			return (0);
		}
	}
	return (1);
}

int	is_valid_buf(char **arr, t_map *map)
{
	int		idx;
	int		idx2;
	char	c;

	idx = 1;
	while (arr[idx])
	{
		idx2 = 0;
		while (arr[idx][idx2])
		{
			c = arr[idx][idx2];
			if (c != map->empty && c != map->obstacle && c != map->full)
				return (1);
			idx2++;
		}
		idx++;
	}
	return (0);
}

int	check_line(t_map *map, char *buf)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (buf[idx])
	{
		if (buf[idx] == '\n')
			cnt++;
		idx++;
	}
	if (map->number_row + 1 == cnt)
		return (0);
	return (1);
}

int	is_length_row(char **arr)
{
	int	idx;
	int	base_len;

	idx = 2;
	base_len = ft_strlen(arr[1]);
	while (arr[idx])
	{
		if (base_len != ft_strlen(arr[idx]))
			return (1);
		idx++;
	}
	return (0);
}

int	is_valid_argc(char **arr, t_map *map, char *buf)
{
	if (is_valid_first_line(arr[0], map) || is_valid_buf(arr, map)
		|| check_line(map, buf) || is_length_row(arr))
	{
		return (1);
	}
	return (0);
}
