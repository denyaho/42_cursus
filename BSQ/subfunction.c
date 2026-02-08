/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:53:43 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/24 23:16:06 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

int	is_valid_word(char c)
{
	if ((31 < c && c < 48) || (57 < c && c < 127))
		return (0);
	return (1);
}

int	is_valid_words(char *buf, int idx)
{
	int	i;

	i = 0;
	while (buf[idx + i])
		i++;
	if (i != 3)
		return (1);
	if (!is_valid_word(buf[idx]))
	{
		if (!is_valid_word(buf[idx + 1]))
		{
			if (!is_valid_word(buf[idx + 2]))
			{
				return (0);
			}
		}
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

void	free_2darr(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
