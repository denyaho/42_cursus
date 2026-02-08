/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:49:53 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/15 21:25:50 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	char	*ptr;

	idx = 0;
	ptr = (char *)s;
	if ((unsigned char)c == '\0')
		return (ptr + ft_strlen(s));
	while (s[idx] != '\0')
	{
		if ((unsigned char)s[idx] == (unsigned char)c)
		{
			return (ptr + idx);
		}
		idx++;
	}
	return (NULL);
}

size_t	real_len(char const *s, unsigned int start, size_t len)
{
	size_t	len_t;

	len_t = 0;
	while (s[start + len_t] && len_t < len)
	{
		len_t++;
	}
	return (len_t);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	idx;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	idx = 0;
	substr = (char *)malloc(sizeof(char) * (real_len(s, start, len) + 1));
	if (substr == NULL)
		return (NULL);
	while (s[start + idx] && idx < len)
	{
		substr[idx] = s[idx + start];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
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
