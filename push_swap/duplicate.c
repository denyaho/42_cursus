/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:04:58 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/26 07:12:46 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	size_arr(char **argv)
{
	int	idx;
	int	size;

	idx = 0;
	while (argv[idx])
		idx++;
	size = idx;
	return (size);
}

static int	*create_arr(char **argv, size_t size)
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	idx = 0;
	while (argv[idx])
	{
		arr[idx] = ft_atoi(argv[idx]);
		idx++;
	}
	return (arr);
}

int	is_duplicate(char **argv, int argc)
{
	int	*arr;
	int	i;
	int	j;

	arr = create_arr(argv, size_arr(argv));
	if (!arr)
		return (1);
	i = 0;
	while (i < size_arr(argv))
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j] && argc == 2)
			{
				free_split_argv(argv);
				return (free(arr), 1);
			}
			else if (arr[i] == arr[j])
				return (free(arr), 1);
			j++;
		}
		i++;
	}
	return (free(arr), 0);
}
