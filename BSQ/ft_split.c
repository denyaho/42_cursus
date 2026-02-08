/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:03:59 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/24 19:04:00 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_charset(char c, char *charset)
{
	int	idx;

	idx = 0;
	while (charset[idx] != '\0')
	{
		if (c == charset[idx])
			return (1);
		idx++;
	}
	return (0);
}

int	count_charset(char *str, char *charset)
{
	int	flag;
	int	cnt;
	int	idx;

	idx = 0;
	flag = 0;
	cnt = 0;
	while (str[idx] != '\0')
	{
		if (find_charset(str[idx], charset) && flag == 0)
		{
			cnt++;
			flag = 1;
		}
		else if (!find_charset(str[idx], charset) && flag == 1)
		{
			flag = 0;
		}
		idx++;
	}
	return (cnt);
}

char	*ft_strdup(char *src, int size)
{
	char	*ans;
	int		idx;

	if (size == 0)
		return (NULL);
	ans = (char *)malloc(sizeof(char) * (size + 1));
	if (ans == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		ans[idx] = src[idx];
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}

int	find_next_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str != '\0' && !find_charset(*str, charset))
	{
		len++;
		str++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		idx;
	int		next_len;

	result = (char **)malloc(sizeof(char *)
			* (count_charset(str, charset) + 2));
	idx = 0;
	while (*str != '\0')
	{
		next_len = find_next_len(str, charset);
		result[idx] = ft_strdup(str, next_len);
		if (result[idx] == NULL)
		{
			str++;
			continue ;
		}
		idx++;
		str += next_len;
	}
	result[idx] = NULL;
	return (result);
}
