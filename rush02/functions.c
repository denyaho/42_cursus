/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:55:42 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/21 16:12:27 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				ans;
	unsigned char	us1;
	unsigned char	us2;

	ans = 0;
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		us1 = (unsigned char)*s1;
		us2 = (unsigned char)*s2;
		if (us1 != us2)
		{
			ans = us1 - us2;
			return (ans);
		}
		s1++;
		s2++;
	}
	return (ans);
}

int	find_key(char *str)
{
	int	idx;

	idx = 0;
	while (g_dict[idx].key[0] != '\0')
	{
		if (ft_strcmp(g_dict[idx].key, str) == 0)
		{
			return (0);
		}
		idx++;
	}
	return (1);
}

char	*make_pow(int num)
{
	char	*str;
	int		idx;

	str = (char *)malloc(sizeof(char) * (num + 2));
	if (str == NULL)
		return (NULL);
	idx = 1;
	str[0] = '1';
	while (idx <= num)
	{
		str[idx] = '0';
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

void	init_array(char *arr)
{
	int	idx;

	idx = 0;
	while (idx < ft_strlen(arr))
	{
		arr[idx] = '\0';
		idx++;
	}
}

int	check_allzero(char *str, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (str[idx] != '0')
			return (0);
		idx++;
	}
	return (1);
}
