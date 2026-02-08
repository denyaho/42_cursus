/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:07:10 by komatsuk          #+#    #+#             */
/*   Updated: 2025/09/21 16:28:11 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	count_entry(int fd)
{
	char	buf[1];
	int		cnt;
	int		size;
	int		flag;

	cnt = 0;
	flag = 0;
	size = read(fd, buf, 1);
	while (size != 0)
	{
		if (size == -1)
		{
			ft_puterror("Dict Error");
			return (-1);
		}
		if (flag && buf[0] == '\n')
			cnt++;
		if (buf[0] == '\n')
			flag = 0;
		else
			flag = 1;
		size = read(fd, buf, 1);
	}
	return (cnt);
}

t_dict	*malloc_dict(char *filename)
{
	t_dict	*dict;
	int		fd;
	int		cnt;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Dict Error");
		return (NULL);
	}
	cnt = count_entry(fd);
	if (cnt == -1)
		return (NULL);
	dict = malloc(sizeof(t_dict) * (cnt + 1));
	if (dict == NULL)
		return (NULL);
	dict[cnt].key[0] = '\0';
	close(fd);
	return (dict);
}

int	split_dict(t_dict *g_dict, int dict_i, char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != ':' && s[i] != ' ')
		g_dict[dict_i].key[j++] = s[i++];
	g_dict[dict_i].key[j] = '\0';
	while (s[i] == ':' || s[i] == ' ')
		i++;
	j = 0;
	while (s[i] != '\n')
		g_dict[dict_i].value[j++] = s[i++];
	g_dict[dict_i].value[j] = '\0';
	return (0);
}

int	assign_dict(t_dict *g_dict, char *buf, int size)
{
	int	inds[2];
	int	flag;
	int	head;

	flag = 0;
	initialize_ij(&inds[0], &inds[1]);
	while (inds[0] < size - 1)
	{
		if (flag == 0 && buf[inds[0]] != '\n')
		{
			head = inds[0];
			flag = 1;
		}
		if (flag && buf[inds[0]] == '\n')
		{
			buf[inds[0]] = '\0';
			if (split_dict(g_dict, inds[1], &buf[head]))
				return (1);
			inds[1]++;
			flag = 0;
		}
		inds[0]++;
	}
	g_dict[inds[1]].key[0] = '\0';
	return (0);
}

int	get_dict(char *filename, t_dict *g_dict)
{
	int		fd;
	int		size;
	char	buf[4096];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	size = read(fd, buf, 4096);
	if (size == -1)
		return (1);
	buf[size] = '\n';
	size += 1;
	assign_dict(g_dict, buf, size);
	return (0);
}
