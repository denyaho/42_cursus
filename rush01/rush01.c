/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:40:19 by daogawa           #+#    #+#             */
/*   Updated: 2026/02/08 15:26:09 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	skyscrapers(int array[][4], int *view);

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

int	count_words(char *str)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (str[idx] == ' ')
		idx++;
	while (str[idx] != '\0')
	{
		if (str[idx] >= '1' && str[idx] <= '9')
			cnt++;
		idx++;
	}
	return (cnt);
}

int	*array_view(char *str, int num)
{
	int	*view;
	int	idx;
	int	idx_array;

	view = (int *)malloc(sizeof(int) * num);
	if (view == NULL)
		return (NULL);
	idx = 0;
	idx_array = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] > '0' && str[idx] <= '4')
		{
			view[idx_array] = str[idx] - '0';
			idx_array++;
		}
		idx++;
	}
	return (view);
}

int	error_handle(int argc, char *str)
{
	int	idx;
	int	flag;

	flag = 0;
	if (argc != 2 || count_words(str) == 0)
		flag = 1;
	if (ft_strlen(str) != 31)
		flag = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (idx % 2 == 0 && !(str[idx] >= '1' && str[idx] <= '4'))
			flag = 1;
		else if (idx % 2 != 0 && str[idx] != ' ')
			flag = 1;
		idx++;
	}
	if (flag)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	array[4][4];
	int	*view;
	int	idx;
	int	idy;

	if (!error_handle(argc, argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	idy = 0;
	while (idy < 4)
	{
		idx = 0;
		while (idx < 4)
		{
			array[idy][idx] = 0;
			idx++;
		}
		idy++;
	}
	view = array_view(argv[1], count_words(argv[1]));
	skyscrapers(array, view);
	free(view);
	return (0);
}
