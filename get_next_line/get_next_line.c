/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:49:28 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/15 21:13:58 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2147483648
#endif

char	*ft_strcat_safe(char *str1, char *str2)
{
	char	*res;
	size_t	idx;
	size_t	idx2;

	if (str1 == NULL)
	{
		str1 = ft_strndup("", 0);
		if (str1 == NULL)
			return (NULL);
	}
	res = (char *)malloc(sizeof(char)
			* (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (res == NULL)
		return (free(str1), NULL);
	idx = 0;
	idx2 = 0;
	while (str1[idx2])
		res[idx++] = str1[idx2++];
	idx2 = 0;
	while (str2[idx2])
		res[idx++] = str2[idx2++];
	res[idx] = '\0';
	return (free(str1), res);
}

char	*push_stock(char **stock)
{
	char	*res;
	size_t	start;
	size_t	size;

	if (!stock || !*stock)
		return (NULL);
	if (!ft_strchr(*stock, '\n'))
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
	start = 0;
	while ((*stock)[start] != '\n')
		start++;
	start++;
	size = ft_strlen(*stock);
	res = ft_substr(*stock, start, size - start);
	free(*stock);
	*stock = NULL;
	return (res);
}

char	*extract_line(char **stock, char *buf)
{
	char	*str;
	char	*res;

	free(buf);
	if (!stock || !*stock)
		return (NULL);
	str = ft_strchr(*stock, '\n');
	if (str != NULL)
		res = ft_strndup(*stock, (str - *stock + 1));
	else
		res = ft_strndup(*stock, ft_strlen(*stock));
	if (res == NULL)
		return (NULL);
	*stock = push_stock(stock);
	return (res);
}

void	free_handle(char **stock, char *buf)
{
	free(*stock);
	free(buf);
	*stock = NULL;
}

char	*get_next_line(int fd)
{
	char		*buf;
	ssize_t		read_byte;
	static char	*stock;

	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (!stock || !ft_strchr(stock, '\n'))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (free_handle(&stock, buf), NULL);
		else if (read_byte == 0)
			break ;
		buf[read_byte] = '\0';
		stock = ft_strcat_safe(stock, buf);
		if (!stock)
			return (free_handle(&stock, buf), NULL);
	}
	if (read_byte == 0 && (stock == NULL || stock[0] == '\0'))
		return (free_handle(&stock, buf), NULL);
	return (extract_line(&stock, buf));
}

// #include <fcntl.h>
// #include <sys/types.h>
// #include <sys/stat.h>

// int main(void)
// {
// 	int		fd;
// 	size_t	lines;
// 	size_t	idx;

// 	fd = open("test.txt", O_RDONLY);
// 	lines = 0;
// 	while (get_next_line(fd))
// 		lines++;
// 	idx = 0;
//     printf("lines is %zu\n", lines);
// 	fd = open("test.txt", O_RDONLY);
// 	while (idx < lines)
// 	{
// 		printf("sentence is %s", get_next_line(fd));
// 		idx++;
// 	}
// }
