/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:45:41 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/09/24 22:51:37 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	x_length(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}

void	free_convert_map(int **map, t_map element)
{
	int	y_index;

	y_index = 0;
	while (y_index < element.number_row)
	{
		free(map[y_index]);
		y_index++;
	}
	free(map);
}

void	free_map(char **map, t_map element)
{
	int	y_index;

	y_index = 0;
	while (y_index < element.number_row - 1)
	{
		free(map[y_index]);
		y_index++;
	}
	free(map);
}

char	*read_put_array2(int fd, char *filename, int *buf_size, int *num_byte)
{
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * *buf_size);
	if (!buf)
		return (NULL);
	*num_byte = read(fd, buf, *buf_size -1);
	while (*num_byte >= *buf_size -1)
	{
		*buf_size *= 2;
		free(buf);
		close (fd);
		fd = open(filename, O_RDONLY);
		buf = (char *)malloc(sizeof(char) * *buf_size);
		if (!buf)
			return (NULL);
		*num_byte = read(fd, buf, *buf_size -1);
	}
	return (buf);
}
