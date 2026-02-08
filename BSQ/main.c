/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:33:34 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/09/24 22:49:31 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "bsq.h"
#include <stdio.h>
#include <fcntl.h>
#include "bsq.h"

#define BUF_SIZE 4096

char	**ft_split(char *str, char *charset);
int		is_valid_argc(char **arr, t_map *map, char *buf);
int		ft_strlen(char *str);
int		ft_isspace(char c);
void	free_2darr(char **arr);
char	*read_put_array2(int fd, char *filename, int *buf_size, int *num_byte);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	read_put_array(int fd, char *filename, int buf_size)
{
	int		num_byte;
	char	*buf;
	char	**arr;
	char	**arr_next;
	t_map	map;

	buf = read_put_array2(fd, filename, &buf_size, &num_byte);
	if (num_byte < 1)
		return (1);
	buf[num_byte] = '\0';
	arr = ft_split(buf, "\n");
	if (is_valid_argc(arr, &map, buf))
		return (1);
	arr_next = arr + 1;
	if (!(search_square(arr_next, map)))
		return (1);
	close(fd);
	free_2darr(arr);
	free(buf);
	return (0);
}

void	get_filename(char *filename)
{
	int		idx;
	int		idx_file;
	char	buf[BUF_SIZE];
	int		num_byte;

	num_byte = read(0, buf, BUF_SIZE - 1);
	buf[num_byte] = '\0';
	idx = 0;
	while (ft_isspace(buf[idx]))
		idx++;
	idx_file = 0;
	while (!ft_isspace(buf[idx]) && buf[idx] != '\0' )
	{
		filename[idx_file] = buf[idx];
		idx++;
		idx_file++;
	}
	filename[idx_file] = '\0';
}

int	read_put_array0(int fd)
{
	char	*filename;

	filename = (char *)malloc(sizeof(char) * 256);
	if (filename == NULL)
		return (0);
	get_filename(filename);
	if (read_put_array(fd, filename, 4096))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	idx;

	idx = 0;
	if (argc == 1)
	{
		if (read_put_array0(0))
			write(1, "map error\n", 10);
	}
	else
	{
		while (++idx < argc)
		{
			if (read_put_array(0, argv[idx], 4096))
			{
				write(1, "map error\n", 10);
			}
			if (idx != argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
