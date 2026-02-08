/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:23:53 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/24 21:10:21 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *str, char c)
{
	size_t	cnt;
	size_t	idx;
	int		flag;

	flag = 0;
	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		if (flag == 0 && str[idx] != c)
		{
			cnt++;
			flag = 1;
		}
		else if (str[idx] == c)
			flag = 0;
		idx++;
	}
	return (cnt);
}

size_t	word_len(char const *str, char set)
{
	size_t	size;

	size = 0;
	while (str[size] != set && str[size])
		size++;
	return (size);
}

void	free_arr(char **str, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

char	*ft_strndup(const char *src, size_t size)
{
	char		*ans;
	size_t		idx;

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

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		idx;

	idx = 0;
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		result[idx] = ft_strndup(s, word_len(s, c));
		if (result[idx] == NULL)
		{
			free_arr(result, idx);
			return (NULL);
		}
		idx++;
		s += word_len(s, c);
	}
	result[idx] = NULL;
	return (result);
}
